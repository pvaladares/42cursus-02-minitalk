/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:56:22 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/20 16:35:08 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*
  Function sets the signals to be caught by the custom handler.
  In case this action fails, prints to stdout an error message and exits the
  program
*/
void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup SIGUSR1 ##\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup SIGUSR2 ##\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

/*
  Functions sends an integer containing the length of the message
  For each bit sent client, waits a signal received back before proceeding
  by using flag = 1 on the send_bit()
  Assumed 1 byte = 8 bits
*/
void	send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

/*
  Function sends 1 char, that normally is an octet (8 bits)
  For each bit sent client, waits a signal received back before proceeding
  by using flag = 1 on the send_bit()
  Assumed 1 byte = 8 bits
*/
void	send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

/*
  Function sends a bit (0 or 1) to the process PID
  Return from function will happen after ACK signal is received in case
  the wait flag is set to non zero, otherwise return immediately
*/
void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR1 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR2 ##\n\e[0m",
				STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}
