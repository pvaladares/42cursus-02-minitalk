/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:38:15 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:25:11 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ATOI(3)                    Library Functions Manual                   ATOI(3)
//
// NAME
//      atoi, atoi_l – convert ASCII string to integer
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <stdlib.h>
//
//      int atoi(const char *str);
//
//      #include <xlocale.h>
//
//      int atoi_l(const char *str, locale_t loc);
//
// DESCRIPTION
//      The atoi() function converts the initial portion of the string pointed
//		to by str to int representation.
//
//      It is equivalent to:
//
//            (int)strtol(str, (char **)NULL, 10);
//
//      While the atoi() function uses the current locale, the atoi_l() 
//		function may be passed a locale directly. See xlocale(3) for more 
//		information.
//
// IMPLEMENTATION NOTES
//      The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
//
//      The strtol() and strtol_l() functions are recommended instead of atoi() 
//		and atoi_l() functions, especially in new code.
//
// ERRORS
//      The function atoi() need not affect the value of errno on an error.

#include "libft.h"

// Now handles extreme cases, spotted after running lib-unit-test
// [KO]: your atoi does not work with over long max value
// [KO]: your atoi does not work with over long min value
//
// INT_MAX =  2147483647 = 0x7FFFFFFF =  2^31 - 1
// Binary representation: 
// 0111 1111 1111 1111 1111 1111 1111 1111
// 31                  15                0
//
// INT_MIN = -2147483648 = 0xFFFFFFFF = -2^31
// Binary representation: 
// 1111 1111 1111 1111 1111 1111 1111 1111
// 31                  15                0
//
// From https://man7.org/linux/man-pages/man3/atoi.3.html
// RETURN VALUE         top
//       The converted value or 0 on error.

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = (result * 10) + (*str - '0');
		if (result > (unsigned int)INT_MAX && sign == 1)
			return (-1);
		else if (result > (unsigned int)INT_MIN && sign == -1)
			return (0);
		str++;
	}
	return ((int)(result * sign));
}
