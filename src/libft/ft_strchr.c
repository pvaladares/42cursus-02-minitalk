/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:27:39 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:58:25 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STRCHR(3)                 Library Functions Manual                 STRCHR(3)
//
// NAME
//      strchr, strrchr – locate character in string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      char *
//      strchr(const char *s, int c);
//
//      char *
//      strrchr(const char *s, int c);
//
// DESCRIPTION
//      The strchr() function locates the first occurrence of c (converted to a
//      char) in the string pointed to by s.  
//		The terminating null character is considered to be part of the string; 
//		therefore if c is ‘\0’, the functions locate the terminating ‘\0’.
//
//      The strrchr() function is identical to strchr(), except it locates the 
//		last occurrence of c.
//
// RETURN VALUES
//      The functions strchr() and strrchr() return a pointer to the located
//      character, or NULL if the character does not appear in the string.

#include "libft.h" // NULL definition

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*s)
	{
		if ((unsigned char)c == *s)
			return ((char *) s);
		s++;
	}
	return (NULL);
}
