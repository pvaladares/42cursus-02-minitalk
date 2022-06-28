/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:13:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/09 11:12:46 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function name    | ft_putnbr
// Prototype        | int ft_putnbr_fd(int n);
// Parameters       | n: The integer to output.
// Return value     | Number of chars written
// External functs. | write
// Description      | Outputs the integer ’n’ to the stdout.
int	ft_putnbr(int n)
{
	size_t					printed;
	unsigned long long int	number;

	printed = 0;
	number = n;
	if (n < 0)
	{
		number = -number;
		printed += ft_putchar('-');
	}
	if (number >= 10)
	{
		printed += ft_putnbr(number / 10);
		printed += ft_putnbr(number % 10);
	}
	else
		printed += ft_putchar(number + '0');
	return (printed);
}
