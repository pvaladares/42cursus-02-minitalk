/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/23 17:27:21 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h> // For testing
#include <signal.h>

void	show_pid(void)
{
	printf("PID process = [%d]\n", getpid());
}

void	server_handler(int num)
{
	;//write(STDOUT_FILENO, &num, 1);
}

int	main(void)
{
	show_pid();
	signal(SIGUSR1, server_handler);
	while (1)
	{
		;
		//show_pid();
		//sleep(1);
	}
	return (0);
}
