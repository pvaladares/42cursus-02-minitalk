/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:48:19 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:16:39 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STRCMP(3)               BSD Library Functions Manual               STRCMP(3)
//
// NAME
//      strcmp, strncmp -- compare strings
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      int strcmp(const char *s1, const char *s2);
//
//      int strncmp(const char *s1, const char *s2, size_t n);
//
// DESCRIPTION
//      The strcmp() and strncmp() functions lexicographically compare the 
//		null-terminated strings s1 and s2.
//
//      The strncmp() function compares not more than n characters.  
//		Because strncmp() is designed for comparing strings rather than binary 
//		data, characters that appear after a `\0' character are not compared.
//
// RETURN VALUES
//      The strcmp() and strncmp() functions return an integer greater than, 
//		equal to, or less than 0, according as the string s1 is greater than, 
//		equal to, or less than the string s2.  The comparison is done using 
//		unsigned characters, so that `\200' is greater than `\0'.

#include "libft.h" // size_t is defined in header <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
