/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:01:45 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/23 17:25:48 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h> // For testing purpose
#include <signal.h>
#include <stdlib.h> // atoi

void	send_bits(int pid_server, unsigned char octet)
{
	int		shift;
	char	mask;
	char	bit;

	shift = 7;
	mask = 1;
	while (shift >= 0)
	{
		bit = (octet >> shift) & mask;
		if (bit == 0)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		shift--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_bits(atoi(argv[1]), atoi(argv[2]));
	else
		printf("\nCorrect syntax:\n./client <server PID> <messsage to send>\n\nExample:\n./client 4242 \"The Answer to the Ultimate Question of Life\"\n\nNote:\nMake sure to run the server first to know the server PID!\n");
	return (0);
}
