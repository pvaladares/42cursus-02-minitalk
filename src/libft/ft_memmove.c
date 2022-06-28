/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:55:30 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:52:15 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MEMMOVE(3)                Library Functions Manual                MEMMOVE(3)
//
// NAME
//      memmove – copy byte string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      void *
//      memmove(void *dst, const void *src, size_t len);
//
// DESCRIPTION
//      The memmove() function copies len bytes from string src to string dst.
//		The two strings may overlap; the copy is always done in a 
//		non-destructive manner.
//
// RETURN VALUES
//      The memmove() function returns the original value of dst.

#include "libft.h" // size_t is defined in header <stdlib.h>

// To be noted that MEMCPY(3) mentions the following:
// Applications in which dst and src might overlap should use memmove(3) 
// instead.

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_aux;
	char		*src_aux;
	char		*dst_last;
	char		*src_last;

	if (!dst && !src)
		return (NULL);
	dst_aux = (char *)dst;
	src_aux = (char *)src;
	if (dst_aux < src_aux)
		while (len--)
			*dst_aux++ = *src_aux++;
	else
	{
		dst_last = dst_aux + (len - 1);
		src_last = src_aux + (len - 1);
		while (len--)
			*dst_last-- = *src_last--;
	}
	return (dst);
}
