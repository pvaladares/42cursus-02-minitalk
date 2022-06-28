/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:29:00 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:59:56 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STRDUP(3)                Library Functions Manual                STRDUP(3)
//
// NAME
//      strdup, strndup – save a copy of a string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      char *
//      strdup(const char *s1);
//
//      char *
//      strndup(const char *s1, size_t n);
//
// DESCRIPTION
//      The strdup() function allocates sufficient memory for a copy of the 
//		string s1, does the copy, and returns a pointer to it.  
//		The pointer may subsequently be used as an argument to the function 
//		free(3).
//
//      If insufficient memory is available, NULL is returned and errno is set
//		to ENOMEM.
//
//      The strndup() function copies at most n characters from the string s1 
//		always NUL terminating the copied string.

#include "libft.h" // errno & NULL definitions

char	*ft_strdup(const char *s1)
{
	char	*aux;

	aux = (char *)malloc(ft_strlen(s1) + 1);
	if (!aux)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(aux, s1, ft_strlen(s1) + 1);
	return (aux);
}
