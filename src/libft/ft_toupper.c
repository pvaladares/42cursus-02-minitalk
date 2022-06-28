/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:22 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:41:28 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TOUPPER(3)                Library Functions Manual               TOUPPER(3)
//
// NAME
//      toupper, toupper_l – lower case to upper case letter conversion
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <ctype.h>
//
//      int toupper(int c);
//
//      #include <ctype.h>
//      #include <xlocale.h>
//
//      int toupper_l(int c, locale_t loc);
//
// DESCRIPTION
//      The toupper() function converts a lower-case letter to the 
//		corresponding uppercase letter.  The argument must be 
//		representable as an unsigned char or the value of EOF.
//
//      Although the toupper() function uses the current locale, the 
//		toupper_l() function may be passed a locale directly. 
//		See xlocale(3) for more information.
//
// RETURN VALUES
//      If the argument is a lower-case letter, the toupper() function 
//		returns the corresponding upper-case letter if there is one; 
//		otherwise, the argument is returned unchanged.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('z' - 'Z'));
	return (c);
}
