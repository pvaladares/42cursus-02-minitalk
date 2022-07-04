/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/04 15:49:21 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
  Function handles the SIGUSR1/SIGUSR2 signals received from server
  
  To be noted that the server will only send a signal upon receiving a 
  signal from server, as explained below:
  - Client sends a bit to server, and (normally) waits a reply - using pause()
  and then
  - The server sends a signal to confirm that each bit was received (ACK)
  or
  - The server sends a signal to confirm that the NULL terminator was received
  (end of string message), and then the function exits
*/
static void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m",
			STDOUT_FILENO);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\e[92m > end of message signal received from server\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

/*
  Function sends the length of the string to server, and then sends the
  string itself, including the null terminator
  
  Note: in the particular case of a null string, it will be sent
  zero as length and then the null terminator string
*/
static void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	{
		ft_putstr_fd("\e[92msending length = [", STDOUT_FILENO);
		ft_putnbr_fd(ft_strlen(str), STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		send_int(server_pid, ft_strlen(str));
		ft_putstr_fd("\e[92msending message\n\e[0m", STDOUT_FILENO);
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		ft_putstr_fd("\e[92msending null string terminator\n\e[0m", STDOUT_FILENO);
		send_char(server_pid, '\0');
	}
}

/*
  This program (client) sends a string message to another process (server)

  The arguments passed from command line are checked if valid
  - string and PID server arguments must be passed, and not more or less
  - PID server must be valid, kill() and ft_atoi() are used to check this
  (not only it must be a valid number as it must be an existing process)

  The sigaction structure is used to catch the user defined signals and 
  take care of the communication with server. Basically for each signal
  sent from client, a reply signal is expected to be received from server
*/
int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_putstr_fd("\e[31m## error - incorrect syntax ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd(
			"\e[92m./client <the server PID> <the string to send>\n\e[0m",
			STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr_fd("\e[31m## error - PID is invalid ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART | SA_NODEFER;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	ft_putstr_fd("\e[92mclient [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	client_send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
