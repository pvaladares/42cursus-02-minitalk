/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/28 12:33:20 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_handler(int num)
{
	if (num == SERVER_REPLY_OK)
		ft_printf("Server replied!\n");
	else if (num == SERVER_REPLY_ERROR)
		ft_printf("Server replied with ERROR\n");
	else
		ft_printf("Server - unkown error!\n");
}

void	send_one_byte(int pid_server, char c)
{
	int		shift;
	char	bit;

	shift = 7;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		if (bit == 0)
		{
			kill(pid_server, BIT_0_OFF);
			ft_printf("0");
		}
		else
		{
			kill(pid_server, BIT_1_ON);
			ft_printf("1");
		}
		shift--;
		usleep(100);
		//pause();
	}
}

void	send_message(int pid_server, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_one_byte(pid_server, str[i]);
		i++;
	}
	send_one_byte(pid_server, str[i]);
}

/*
	Function checks whether the PID is valid
	Returns 1 if it is valid (PID > 0), else returns 0
*/
int	is_pid_valid(char *str)
{
	if (ft_atoi(str) <= 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{	
	if (argc != 3)
	{
		ft_printf("Error : Incorrect syntax, see below the correct syntax.\n");
		ft_printf("./client <server PID> <messsage to send>\n");
		exit(EXIT_FAILURE);
	}
	else if (is_pid_valid(argv[1]) == 0)
	{
		ft_printf("Error : Incorrect PID format detected.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal(SERVER_REPLY_OK, client_handler);
		signal(SERVER_REPLY_ERROR, client_handler);
		printf("Sending a message with [%zu] chars\n", ft_strlen(argv[2]));
		//send_one_byte(ft_atoi(argv[1]), argv[2][0]);
		//pause();
		send_message(ft_atoi(argv[1]), argv[2]);
		/*
		while (1)
		{
			pause();
			exit (EXIT_SUCCESS);
		}
		*/
	}
}
