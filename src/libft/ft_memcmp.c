/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:27:19 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:50:01 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MEMCMP(3)                Library Functions Manual                MEMCMP(3)
//
// NAME
//      memcmp – compare byte string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      int
//      memcmp(const void *s1, const void *s2, size_t n);
//
// DESCRIPTION
//      The memcmp() function compares byte string s1 against byte string s2.  
//		Both strings are assumed to be n bytes long.
//
// RETURN VALUES
//      The memcmp() function returns zero if the two strings are identical, 
//		otherwise returns the difference between the first two differing bytes 
//		(treated as unsigned char values, so that ‘\200’ is greater than ‘\0’,
//		for example).
//		Zero-length strings are always identical.  
//		This behavior is not required by C and portable code should only depend
//		on the sign of the returned value.

#include "libft.h" // size_t is defined in header <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
