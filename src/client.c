/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 13:47:15 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
  Function handles the signals (SIGUSR1/2) received from server
  (see details on minitalk.h)
  To be noted that the server is only expected to send signals after
  receiving signals from the client:
  - The server sends a signal to confirm that the NULL terminator was received
  (end of string message); then the function exits
  - The server sends a signal to confirm that bit was received
*/
void	client_handler(int sig)
{
	static int	bits_counter;

	if (sig == SERVER_REPLY_ACK)
	{
		bits_counter++;
		//ft_putstr("ACK signal received from server\n");
	}
	else if (sig == SERVER_REPLY_NULL_TERMINATOR)
	{
		ft_putstr("end of message signal received from server\n");
		ft_putstr("received from server [%d] ACK bits");
		//ft_printf("received from server [%d] ACK bits\n", bits_counter);
		//ft_printf("received from server [%d] bytes\n", bits_counter / 8);
		exit(EXIT_SUCCESS);
	}
}

/*
  Function sends the length of the string to server, and then sends the
  string itself, including the null terminator
  In case the string is empty, e.g. '' or "", function will send
  only the length zero
*/
void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		send_int(server_pid, 0);
	else
	{
		//ft_printf("sending length of message = [%d]\n", ft_strlen(str));
		send_int(server_pid, ft_strlen(str));
		ft_putstr("sending message\n");
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		ft_putstr("sending null string terminator\n");
		send_char(server_pid, '\0');
	}
}

/*
  This program (client) sends a string message to another process (server)
  
  The arguments passed are checked if are valid:
  - string and PID server arguments must be passed, and not more or less
  - PID server must exist, kill() and ft_atoi() are used to check this

  The sigaction structure is used to catch the signals (SIGUSR1/2) and 
  take care of the communication with server. Basically for each signal
  sent from client, a reply signal must be received from server
*/
int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_putstr("## error - incorrect syntax ##\n");
		ft_putstr("./client <the server PID> <the string to send>\n");
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr("## error - PID is invalid ##\n");
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART | SA_NODEFER;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	ft_printf("client [PID = %d]: sending message\n", getpid());
	client_send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
