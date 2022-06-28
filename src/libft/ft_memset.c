/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:11 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:31:02 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MEMSET(3)                 Library Functions Manual                MEMSET(3)
//
// NAME
//      memset – fill a byte string with a byte value
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      void *memset(void *b, int c, size_t len);
//
// DESCRIPTION
//      The memset() function writes len bytes of value c (converted to an 
//  	unsigned char) to the string b.
//
// RETURN VALUES
//      The memset() function returns its first argument.

#include "libft.h" // size_t is defined in header <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *) b)[i] = c;
		i++;
	}
	return (b);
}
