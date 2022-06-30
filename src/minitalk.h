/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/30 13:47:53 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h" // ft_atoi(), ft_strlen(), ft_putstr()
# include "printf/ft_printf.h" // ft_printf()
# include <unistd.h> // getpid()
# include <signal.h> // signal()
# include <stdlib.h> // exit()

# define BIT_0_OFF						SIGUSR1
# define BIT_1_ON						SIGUSR2
# define SERVER_REPLY_ACK				SIGUSR1
# define SERVER_REPLY_NULL_TERMINATOR	SIGUSR2
# define EXIT_USER_INTERACTION			SIGINT // Using value as SIGINT (CTRL+C), 2

/*
  From opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/proc_internal.h

  * We use process IDs <= PID_MAX; PID_MAX + 1 must also fit in a pid_t,
  * as it is used to represent "no process group".

  #define PID_MAX         99999
*/
# define PID_MAX				99999

# define WAIT_US				0 //usleep(WAIT_US)


void	configure_sigaction_signals(struct sigaction *sa);
void	send_char(pid_t pid, char c);
void	send_bit(pid_t pid, char bit);
void	send_int(pid_t pid, int num);

#endif
