/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:19 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:41:07 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TOLOWER(3)                 Library Functions Manual                TOLOWER(3)
//
// NAME
//      tolower, tolower_l – upper case to lower case letter conversion
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <ctype.h>
//
//      int tolower(int c);
//
//      #include <ctype.h>
//      #include <xlocale.h>
//
//      int tolower_l(int c, locale_t loc);
//
// DESCRIPTION
//      The tolower() function converts an upper-case letter to the 
//		corresponding lower-case letter.  The argument must be representable as 
//		an unsigned char or the value of EOF.
//
//      Although the tolower() function uses the current locale, the tolower_l()
//		function may be passed a locale directly. See xlocale(3) for more 
//		information.
//
// RETURN VALUES
//      If the argument is an upper-case letter, the tolower() function returns 
//		the corresponding lower-case letter if there is one; otherwise, 
//		the argument is returned unchanged.

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('z' - 'Z'));
	return (c);
}
