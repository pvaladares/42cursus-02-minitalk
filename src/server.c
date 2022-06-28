/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/28 16:15:52 by pvaladar         ###   ########.fr       */
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
  Functions shows the server PID so user can type it
  when executing the client
*/
void	server_show_pid(void)
{
	ft_printf("[PID = %d] server started\n", getpid());
}

/*
  Function catches the user keyboard (CTRL+C == SIGINT == 2)
  prints a message and exits the program
*/
void	server_show_user_ended(void)
{
	ft_printf("\n[PID = %d] server ended : user instruction\n", getpid());
	exit(EXIT_USER_INTERACTION);
}

void	server_show_kill_error(void)
{
	ft_printf("Server error : kill()\n");
	exit(EXIT_FAILURE);
}

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
	static int	bits_received[PID_MAX];
	static int	char_received[PID_MAX];
	size_t		client_pid;

	(void)info;
	(void)context;
	client_pid = info->si_pid;
	if (bits_received[client_pid] == 0)
		char_received[client_pid] = 0;
	if (num == SIGINT)
		server_show_user_ended();
	if (num == BIT_0_OFF || num == BIT_1_ON)
	{
		if (num == BIT_1_ON)
			char_received[client_pid] |= 1 << (7 - bits_received[client_pid]);
		if (kill(client_pid, SERVER_REPLY_ACK) == -1)
			server_show_kill_error();
	}
	if (++bits_received[client_pid] == 8)
	{
		ft_printf("Char received %c %d\n", char_received[client_pid], char_received[client_pid]);
		bits_received[client_pid] = 0;
		char_received[client_pid] = 0;
	}
}

/*
  Using signal() to define which signals to catch by the handlers
  The infinite loop will just keep the process running, the pause()
  The pause() function causes the calling thread to pause until a
  signal is received
*/
int	main(void)
{
	struct sigaction	s_server_sigaction;
	//sigset_t			block_mask;

	server_show_pid();
	s_server_sigaction.sa_sigaction = server_handler;
	//s_server_sigaction.sa_mask = 0;
	s_server_sigaction.sa_flags = SA_SIGINFO;
	//sigemptyset(&block_mask);
	//sigaddset(&block_mask, SIGINT);
	//sigaddset(&block_mask, SIGQUIT);
	//sa_signal.sa_handler = 0;
	//sa_signal.sa_flags = SA_SIGINFO;
	//sa_signal.sa_mask = block_mask;
	sigaction(BIT_0_OFF, &s_server_sigaction, NULL);
	sigaction(BIT_1_ON, &s_server_sigaction, NULL);
	sigaction(SIGINT, &s_server_sigaction, NULL);
	//sigaction(SIGINT, &sa_signal, NULL);
	//signal(SIGINT, server_show_ended);
	//signal(BIT_0_OFF, server_handler);
	//signal(BIT_1_ON, server_handler);
	while (1)
	{
		pause();
		usleep(50);
	}
	exit(EXIT_SUCCESS);
}
