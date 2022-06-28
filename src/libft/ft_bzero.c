/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:34:47 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:28:27 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BZERO(3)                BSD Library Functions Manual                BZERO(3)
//
// NAME
//      bzero -- write zeroes to a byte string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <strings.h>
//
//      void
//      bzero(void *s, size_t n);
//
// DESCRIPTION
//      The bzero() function writes n zeroed bytes to the string s.  
//		If n is zero, bzero() does nothing.

#include "libft.h" // size_t is defined in header <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
