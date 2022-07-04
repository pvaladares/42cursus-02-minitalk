/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/04 15:12:51 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h" // ft_atoi(), ft_strlen(), ft_putstr(), ft_putnbr()
# include <unistd.h> // getpid()
# include <signal.h> // signal()
# include <stdlib.h> // exit()

# define WAIT_US				100 //usleep(WAIT_US)

void	configure_sigaction_signals(struct sigaction *sa);
void	send_char(pid_t pid, char c);
void	send_bit(pid_t pid, char bit, char flag_to_pause);
void	send_int(pid_t pid, int num);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

/*
  Structure to handle the protocol between server-client
  
  bits : bits received
  data : data received, can be an integer (length of message) or char
  flag : 1 if length of message was received, else 0
  message : message received
*/
typedef struct s_protocol
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}			t_protocol;

#endif
