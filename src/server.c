/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 16:19:32 by pvaladar         ###   ########.fr       */
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
	static int	i;

	//usleep(WAIT_US);
	(void)info;
	(void)context;
	client_pid = info->si_pid;
	if (bits_received == 0)
		info_received = 0;
	if (num == BIT_1_ON && flag_length_received == 0)
		info_received |= 1 << (((sizeof(int) * 8) - 1) - bits_received);
	else if (num == BIT_1_ON && flag_length_received == 1)
		info_received |= 1 << (((sizeof(char) * 8) - 1) - bits_received);
	bits_received++;	
	if (bits_received == 8 && flag_length_received == 1)
	{
		message[i++] = info_received;
		//ft_printf("%c", info_received);
		if (info_received == '\0')
		{
			//ft_printf("received message = [%s]\n", message);
			ft_putstr(message);
			free(message);
			message = NULL;
			flag_length_received = 0;
			i = 0;
			bits_received = 0;
			kill(client_pid, SERVER_REPLY_NULL_TERMINATOR);
		}
		bits_received = 0;
	}
	if (bits_received == sizeof(int) * 8 && flag_length_received == 0)
	{
		flag_length_received = 1;
		//ft_printf("received length of message = [%d]\n", info_received);
		ft_putstr("received length of message = ");
		ft_putnbr(info_received);
		message = ft_calloc(info_received + 1, sizeof(char));
		if (message == NULL)
			exit(EXIT_FAILURE);
		message[info_received] = '\0';
		bits_received = 0;
	}
	kill(client_pid, SERVER_REPLY_ACK);
}

/*
  This program (server) prints to stdout the PID process and keeps
  listening for incoming message transmissions
  
  Each client should the following sequence:
         (int)              (char)               (char)
    length of message -> regular chars -> null string terminator char

  The string message is only printed to stdout when the full string is received
  For each signal received from client, this program (server) sends
  a corresponding signal back
  
  Using sigaction structure to define which signals to catch by the handler
  The infinite loop will just keep the process running
  
  The pause() function causes the calling thread to pause until a
  signal is received
*/
int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	configure_sigaction_signals(&s_server);
	ft_printf("[PID = %d] server started\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
