/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:56:22 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 10:42:06 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 4) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bit(pid, bit);
		shift--;
	}
}

void	send_byte(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = 7;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bit(pid, bit);
		shift--;
	}
}

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
