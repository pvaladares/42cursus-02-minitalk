/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:26:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:43:35 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MEMCHR(3)                 Library Functions Manual                 MEMCHR(3)
//
// NAME
//      memchr – locate byte in byte string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      void *
//      memchr(const void *s, int c, size_t n);
//
// DESCRIPTION
//      The memchr() function locates the first occurrence of c (converted to an
//      unsigned char) in string s.
//
// RETURN VALUES
//      The memchr() function returns a pointer to the byte located, or NULL if
//		no such byte exists within n bytes.

#include "libft.h" // size_t is defined in header <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
