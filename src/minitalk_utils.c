/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:20:09 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/04 11:20:17 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, STDOUT_FILENO);
}
