/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/28 12:21:54 by pvaladar         ###   ########.fr       */
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

void	server_show_pid(void)
{
	ft_printf("[PID = %d] Server started\n", getpid());
}

/*
  Function catches the user keyboard (CTRL+C),
  prints a message, and then proceeds with the default
  action which is to terminate the process
*/
void	server_show_ended(int num)
{
	if (num == SIGINT)
	{
		ft_printf("\n[PID = %d] Server ended - user instruction\n", getpid());
		exit(EXIT_USER_INTERACTION);
	}
}

/*
  Function catch the signals received from client that represent the status 
  on each bit (either 0 or 1), using SIGUSR1 and SIGUSR2
  For cleaner code a definition was used, refer to the header file
*/
// void handler(int, siginfo_t *info, ucontext_t *uap);
void	server_handler(int num, siginfo_t *info, void *context)
{
	static int	bits_received;
	static char	char_received;

	(void)info;
	(void)context;
	if (bits_received == 0)
		char_received = 0;
	if (num == BIT_0_OFF)
	{
		ft_printf("0");
		kill(info->si_pid, SERVER_REPLY_OK);
	}
	else if (num == BIT_1_ON)
	{
		ft_printf("1");
		char_received |= 1 << (7 - bits_received);
		kill(info->si_pid, SERVER_REPLY_OK);
	}
	if (++bits_received == 8)
	{
		ft_printf("Char received = [%c]\n", char_received);
		bits_received = 0;
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
	struct sigaction	s_server;
	//sigset_t			block_mask;

	s_server.sa_sigaction = server_handler;
	s_server.sa_mask = 0;
	s_server.sa_flags = SA_SIGINFO;
	//sigemptyset(&block_mask);
	//sigaddset(&block_mask, SIGINT);
	//sigaddset(&block_mask, SIGQUIT);
	//sa_signal.sa_handler = 0;
	//sa_signal.sa_flags = SA_SIGINFO;
	//sa_signal.sa_mask = block_mask;
	sigaction(SIGUSR1, &s_server, NULL);
	sigaction(SIGUSR2, &s_server, NULL);
	//sigaction(SIGINT, &sa_signal, NULL);
	//signal(SIGINT, server_show_ended);
	//signal(BIT_0_OFF, server_handler);
	//signal(BIT_1_ON, server_handler);
	server_show_pid();
	while (1)
	{
		pause();
		sleep(1);
	}
	return (0);
}
