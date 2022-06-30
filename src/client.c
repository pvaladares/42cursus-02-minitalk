/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 11:12:44 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_handler(int sig)
{
	static int	bits_counter;
	//int			bytes_counter;

	if (sig == SERVER_REPLY_ACK)
	{
		bits_counter++;
		ft_putstr("ACK signal received from server\n");
	}
	else if (sig == SERVER_REPLY_NULL_TERMINATOR)
	{
		//bytes_counter = ++bits_counter / 8;
		ft_putstr("end of message signal received from server\n");
		ft_printf("received from server [%d] ACK bits\n", bits_counter);
		ft_printf("received from server [%d] bytes\n", bits_counter / 8);
		exit(EXIT_SUCCESS);
	}
}

/*
  Function sends the string to the server, including the null terminator
  In case the string is empty, e.g. '' or "", function will send
  the null terminator to server
*/
void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		send_int(server_pid, 0);
	else
	{
		send_int(server_pid, ft_strlen(str));
		while (str[i] != '\0')
			send_byte(server_pid, str[i++]);
		send_byte(server_pid, '\0');
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_putstr("## error - incorrect syntax ##\n");
		ft_putstr("./client <server PID> <messsage to send>\n");
		return (EXIT_FAILURE);
	}
	else if (kill(atoi(argv[1]), 0) < 0)
	{
		ft_putstr("## error - PID is invalid ##\n");
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = 0;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	ft_printf("client [PID = %d]: sending message\n", getpid());
	ft_printf("Length of message = %d\n", ft_strlen(argv[2]));
	client_send_message(atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
