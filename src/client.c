/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/29 12:29:26 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_handler(int num, siginfo_t *info, void *context)
{
	static int	bits_counter;

	(void)info;
	(void)context;
	if (num == SERVER_REPLY_ACK && ++bits_counter)
		ft_printf("server message: ack signal received\n");
	else if (num == SERVER_REPLY_ERROR)
		ft_printf("server message: total chars received [%d]\n",
			bits_counter / 8);
}

void	client_send_byte(int pid_server, char c)
{
	int		shift;
	char	bit;

	shift = 7;
	while (shift >= 0)
	{
		usleep(WAIT_US);
		bit = (c >> shift) & 1;
		if (bit == 0)
		{
			if (kill(pid_server, BIT_0_OFF) < 0)
			{
				ft_printf("client error: kill()\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (bit == 1)
		{
			if (kill(pid_server, BIT_1_ON) < 0)
			{
				ft_printf("client error: kill()\n");
				exit(EXIT_FAILURE);
			}
		}
		shift--;
		pause();
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

	if (str[0] == '\0')
		client_send_byte(server_pid, '\0');
	else
	{
		i = 0;
		while (str[i] != '\0')
			client_send_byte(server_pid, str[i++]);
		client_send_byte(server_pid, '\0');
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	s_client;
	int					server_pid;
	char				*message;

	message = argv[2];
	if (argc != 3)
	{
		ft_printf("client error: incorrect syntax, see below\n");
		ft_printf("./client <server PID> <messsage to send>\n");
		exit(EXIT_FAILURE);
	}
	else if (kill(atoi(argv[1]), 0) < 0)
	{
		ft_printf("client error: PID is invalid\n");
		exit(EXIT_FAILURE);
	}
	server_pid = atoi(argv[1]);
	//
	s_client.sa_sigaction = client_handler;
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_SIGINFO;
	//
	if (sigaction(SERVER_REPLY_ACK, &s_client, NULL) < 0
		|| sigaction(SERVER_REPLY_ERROR, &s_client, NULL) < 0)
	{
		ft_printf("client error: sigaction()");
		exit(EXIT_FAILURE);
	}
	//client_send_byte(server_pid, length);
	//printf("Sent length [%zu]\n", length);
	client_send_message(server_pid, message);
	ft_printf("client: sent message with length [%d]\n",  ft_strlen(message));
	exit(EXIT_SUCCESS);
}
