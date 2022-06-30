/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:56:22 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 13:05:25 by pvaladar         ###   ########.fr       */
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
		ft_putstr("## error - could not setup SIGUSR1 ##\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr("## error - could not setup SIGUSR2 ##\n");
		exit(EXIT_FAILURE);
	}
}

/*
  Functions sends an integer containing the length of the message
  Using `sizeof()` so the code is portable between different architectures
*/
void	send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bit(pid, bit);
		shift--;
	}
}

/*
  Function sends 1 char, that normally is an octet (8 bits)
  Using `sizeof()` so the code is portable between different architectures
*/
void	send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bit(pid, bit);
		shift--;
	}
}

/*
  Function sends a bit (0 or 1) to the process PID
  Return will happen after ACK signal is received (implemented on 
  signal handlers)
*/
void	send_bit(pid_t pid, char bit)
{
	if (bit == 0)
	{
		if (kill(pid, BIT_0_OFF) < 0)
		{
			ft_putstr("## error - sending signal 0 ##\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, BIT_1_ON) < 0)
		{
			ft_putstr("## error - sending signal 1 ##\n");
			exit(EXIT_FAILURE);
		}
	}
	pause();
}
