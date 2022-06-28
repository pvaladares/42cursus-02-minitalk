/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/28 16:18:11 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_handler(int num, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (num == SERVER_REPLY_ACK)
		ft_printf("[Debug : Server replied]\n");
	else if (num == SERVER_REPLY_ERROR)
		ft_printf("Server replied with ERROR\n");
	else
		ft_printf("Server - unkown error!\n");
}

void	client_send_byte(int pid_server, char c)
{
	int		shift;
	char	bit;

	shift = 7;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		if (bit == 0)
		{
			if (kill(pid_server, BIT_0_OFF) == -1)
			{
				ft_printf("Error client - kill()\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (kill(pid_server, BIT_1_ON) == -1)
		{
			ft_printf("Error client - kill()\n");
			exit(EXIT_FAILURE);
		}
		shift--;
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

void	client_check_inputs(int argc, size_t server_pid)
{
	if (argc != 3)
	{
		ft_printf("Client error : Incorrect syntax, see below\n");
		ft_printf("./client <server PID> <messsage to send>\n");
		exit(EXIT_FAILURE);
	}
	else if (server_pid <= 0)
	{
		ft_printf("Client error : Incorrect PID detected\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	s_client_sigaction;
	size_t				length;
	size_t				server_pid;
	char				*message;

	server_pid = ft_atoi(argv[1]);
	client_check_inputs(argc, server_pid);
	message = argv[2];
	length = ft_strlen(message);
//
	s_client_sigaction.sa_sigaction = client_handler;
	//s_client_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SERVER_REPLY_ACK, &s_client_sigaction, NULL);
	sigaction(SERVER_REPLY_ERROR, &s_client_sigaction, NULL);
//
	//client_send_byte(server_pid, length);
	//printf("Sent length [%zu]\n", length);
	client_send_message(server_pid, message);
	printf("Sent message with length [%zu]\n", length);
	exit(EXIT_SUCCESS);
}
