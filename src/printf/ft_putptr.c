/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:34:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/09 11:15:09 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Info about `uintptr_t` data type
// https://stackoverflow.com/questions/1845482/what-is-uintptr-t-data-type
int	ft_putptr(uintptr_t n, char *base)
{
	size_t	printed;
	size_t	base_length;

	printed = 0;
	base_length = ft_strlen(base);
	if (n >= (uintptr_t)base_length)
	{
		printed += ft_putptr(n / base_length, base);
		printed += ft_putptr(n % base_length, base);
	}
	else
		printed += ft_putchar(base[n % base_length]);
	return (printed);
}
