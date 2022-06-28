/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:39:50 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:38:14 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ISASCII(3)                 Library Functions Manual                ISASCII(3)
//
// NAME
//      isascii – test for ASCII character
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// // SYNOPSIS
//		#include <ctype.h>
//
//		int isascii(int c);
//
// DESCRIPTION
//      The isascii() function tests for an ASCII character, which is any
//      character between 0 and octal 0177 inclusive.
//
//
//	"an integer digit preceded by 0 is interpreted as an octal number"
// 	https://www.geeksforgeeks.org/octal-numbers-c/
//
//		   0 = NULL
//		0177 = DELete

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 0177);
}
