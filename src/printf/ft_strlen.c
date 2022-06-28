/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:15 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/09 11:49:18 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// STRLEN(3)                  Library Functions Manual               STRLEN(3)
//
// NAME
//      strlen – find length of string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      size_t strlen(const char *s);
////
// DESCRIPTION
//      The strlen() function computes the length of the string s.  
//
// RETURN VALUES
//      The strlen() function returns the number of characters that precede the
//      terminating NULL character. 
//
// Change log:
// 2022/06/08 Changed to fit the behaviour of printf with NULL string 
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
