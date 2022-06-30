/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 11:13:27 by pvaladar         ###   ########.fr       */
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
	if (num == SIGINT)
	{
		ft_printf("\nserver: interrupted by user\n");
		exit(EXIT_USER_INTERACTION);
	}*/

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
	size_t		client_pid;
	static int	bits_received;
	static int	info_received;
	static char	flag_length_received;
	static char	*message;

	usleep(WAIT_US);
	(void)info;
	(void)context;
	client_pid = info->si_pid;
	if (bits_received == 0)
		info_received = 0;
	else if (num == BIT_1_ON && flag_length_received == 0)
		info_received |= 1 << (((sizeof(int) * 4) - 1) - bits_received);
	else if (num == BIT_1_ON && flag_length_received == 1)
		info_received |= 1 << (7 - bits_received);
	if (++bits_received == sizeof(int) * 4 && flag_length_received == 0)
	{
		flag_length_received = 1;
		ft_printf("Length of message = %d\n", info_received);
		bits_received = 0;
		info_received = 0;
	}
	else if (bits_received == 8 && flag_length_received == 1)
	{
		ft_printf("%c", info_received);
		if (info_received == '\0')
		{

			kill(client_pid, SERVER_REPLY_NULL_TERMINATOR);
		}
		bits_received = 0;
		info_received = 0;
		//flag_length_received = 0;
	}
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

	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO;
	configure_sigaction_signals(&s_server);
	ft_printf("server [PID = %d]: listening for messages\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
