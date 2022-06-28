/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:23:37 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/09 11:50:08 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function name    | ft_u_putnbr_base
// Prototype        | int ft_u_putnbr_base(unsigned int n, char *base);
// Parameters       | n: The unsigned integer to output (assumed to be base 10).
//					| base: The output base the number should be displayed
// Return value     | Number of chars written
// External functs. | write
// Description      | Outputs the integer ’n’ to the stdout in the given base.
//
// Note: In this implementation a static variable is usedd to keep the
// balance of total chars already printed between recursive calls to the 
// function
int	ft_u_putnbr_base(unsigned int n, char *base)
{
	size_t					printed;
	size_t					base_length;
	unsigned long long int	number;

	printed = 0;
	number = n;
	base_length = ft_strlen(base);
	if (number >= (uintptr_t)base_length)
	{
		printed += ft_putnbr_base(number / base_length, base);
		printed += ft_putnbr_base(number % base_length, base);
	}
	else
		printed += ft_putchar(base[number % base_length]);
	return (printed);
}
