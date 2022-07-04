/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:56:22 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/04 11:31:35 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
  Function sets the signals to be caught by the custom handler.
  In case this action fails, prints to stdout an error message and exit the
  program
*/
void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup SIGUSR1 ##\n\e[0m", 1);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup SIGUSR2 ##\n\e[0m", 1);
		exit(EXIT_FAILURE);
	}
}

/*
  Functions sends an integer containing the length of the message
  Assumed 1 byte = 8 bits
  Using `sizeof()` so the code should be portable between different architectures
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
  Assumed 1 byte = 8 bits
  Using `sizeof()` so the code should be portable between different architectures
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
  Return will happen after ACK signal is received (implemented on 
  signal handlers), in case the flag is set to non zero
*/
void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr("\e[31m## error - sending SIGUSR1 ##\n\e[0m");
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putstr("\e[31m## error - sending SIGUSR2 ##\n\e[0m");
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}
