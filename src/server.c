/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/29 12:29:32 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Features
  - Error detection input: number of arguments and type of argument
  - Error catching for functions
  - Convert char to binary using bitwise operations (fast)
  - Send/receive bits if sender/receiver are available and ack each bit
  - Server able to workout from which client the bits are coming
  - Checksum?
*/

/*
  Function catches the user keyboard (CTRL+C == SIGINT == 2)
  prints a message and exits the program
*/
void	server_show_user_ended(void);

/*
  Function catches signals received from client that represents the status 
  on each bit (either 0 or 1), using SIGUSR1 and SIGUSR2
  For cleaner code a definition was used, refer to the header file
  Added functionality to handle several clients at the same type, now the 
  bits and char received are arrays and the client PID is the index
  This way the server knows from which client the signals was received
  querying the sigaction structure (si_pid)
  Variables declared as static are initialized with zero, and after each 
  8 bits received they are again re-initialized to zero
  For each bit received from client, the server sends an ACK signal
  (then the client should only send the next bit after this ACK signal)
*/
void	server_handler(int num, siginfo_t *info, void *context)
{
	static int	bits_received;
	static int	char_received;
	size_t		client_pid;

	(void)info;
	(void)context;
	client_pid = info->si_pid;
	if (bits_received == 0)
		char_received = 0;
	if (num == SIGINT)
	{
		ft_printf("\nserver ended: user instruction\n");
		exit(EXIT_USER_INTERACTION);
	}
	if (num == BIT_1_ON)
		char_received |= 1 << (7 - bits_received);
	if (++bits_received == 8)
	{
		ft_printf("%c", char_received);
		bits_received = 0;
		char_received = 0;
	}
	usleep(WAIT_US);
	kill(client_pid, SERVER_REPLY_ACK);
}

/*
  Using signal() to define which signals to catch by the handlers
  The infinite loop will just keep the process running, the pause()
  The pause() function causes the calling thread to pause until a
  signal is received
*/
int	main(void)
{
	struct sigaction	s_server;

	s_server.sa_sigaction = server_handler;
	sigemptyset(&s_server.sa_mask);
	s_server.sa_flags = SA_SIGINFO;
	if (sigaction(BIT_0_OFF, &s_server, NULL) < 0
		|| sigaction(BIT_1_ON, &s_server, NULL) < 0
		|| sigaction(SIGINT, &s_server, NULL) < 0)
	{
		ft_printf("server error: sigaction()");
		exit(EXIT_FAILURE);
	}
	ft_printf("server started: [PID = %d]\n", getpid());
	while (1)
	{
		pause();
	}
	exit(EXIT_SUCCESS);
}
