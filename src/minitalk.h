/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/27 22:15:05 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "printf/ft_printf.h" // ft_printf()
# include <unistd.h> // write(), getpid()
# include <signal.h> // signal()
# include <stdlib.h> // exit(), atoi()
# include <stdio.h> // For testing
# include <sys/signal.h> // remove

# define BIT_0_OFF				SIGUSR1
# define BIT_1_ON				SIGUSR2
# define SERVER_REPLY_OK		SIGUSR1
# define SERVER_REPLY_ERROR		SIGUSR2
# define EXIT_USER_INTERACTION	SIGINT // Using value as SIGINT (CTRL+C), 2

#endif
