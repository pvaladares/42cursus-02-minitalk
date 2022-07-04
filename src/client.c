/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/04 11:24:15 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
  Function handles the signals (SIGUSR1/SIGUSR2) received from server
  To be noted that the server is only expected to send signals after
  receiving signals from the client, as follows:
  - The server sends a signal to confirm that the NULL terminator was received
  (end of string message); then the function exits
  - The server sends a signal to confirm that each bit was received
*/
void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("\e[33m > ACK signal received from server\n\e[0m");
	else if (sig == SIGUSR2)
	{
		ft_putstr("\e[92m > end of message signal received from server\n\e[0m");
		exit(EXIT_SUCCESS);
	}
}

/*
  Function sends the length of the string to server, and then sends the
  string itself, including the null terminator
*/
void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	{
		ft_putstr("\e[92msending length = [");
		ft_putnbr(ft_strlen(str));
		ft_putstr("]\n\e[0m");
		send_int(server_pid, ft_strlen(str));
		ft_putstr("\e[92msending message\n\e[0m");
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		ft_putstr("\e[92msending null string terminator\n\e[0m");
		send_char(server_pid, '\0');
	}
}

/*
  This program (client) sends a string message to another process (server)

  The arguments passed are checked if are valid:
  - string and PID server arguments must be passed, and not more or less
  - PID server must exist, kill() and ft_atoi() are used to check this

  The sigaction structure is used to catch the user defined signals and 
  take care of the communication with server. Basically for each signal
  sent from client, a reply signal must be received from server
*/
int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_putstr("\e[31m## error - incorrect syntax ##\n\e[0m");
		ft_putstr("\e[92m./client <the server PID> <the string to send>\n\e[0m");
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr("\e[31m## error - PID is invalid ##\n\e[0m");
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART | SA_NODEFER;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	ft_putstr("\e[92mclient [PID = ");
	ft_putnbr(getpid());
	ft_putstr("]\n\e[0m");
	client_send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
