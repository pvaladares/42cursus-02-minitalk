/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:15 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:10:19 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STRLEN(3)                  Library Functions Manual               STRLEN(3)
//
// NAME
//      strlen, strnlen – find length of string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      size_t strlen(const char *s);
//
//      size_t strnlen(const char *s, size_t maxlen);
//
// DESCRIPTION
//      The strlen() function computes the length of the string s.  
//      The strnlen() function attempts to compute the length of s, 
//  	but never scans beyond the first maxlen bytes of s.
//
// RETURN VALUES
//      The strlen() function returns the number of characters that precede the
//      terminating NUL character.  The strnlen() function returns either the 
//  	same result as strlen() or maxlen, whichever is smaller.

#include "libft.h" // size_t is defined in header <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
