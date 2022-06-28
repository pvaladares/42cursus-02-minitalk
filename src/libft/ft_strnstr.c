/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:35:26 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:19:53 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// STRSTR(3)                Library Functions Manual                STRSTR(3)
//
// NAME
//      strnstr – locate a substring in a string
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <string.h>
//
//      char *
//      strnstr(const char *haystack, const char *needle, size_t len);

// DESCRIPTION
//      The strnstr() function locates the first occurrence of the 
//		null-terminated string needle in the string haystack, where not more 
//		than len characters are searched.
//      Characters that appear after a ‘\0’ character are not searched.  
//		Since the strnstr() function is a FreeBSD specific API, it should only 
//		be used when portability is not a concern.
//
// RETURN VALUES
//      If needle is an empty string, haystack is returned; if needle occurs 
//		nowhere in haystack, NULL is returned; otherwise a pointer to the first
//		character of the first occurrence of needle is returned.
//
// EXAMPLES
//      The following sets the pointer ptr to NULL, because only the first 
//		4 characters of largestring are searched:
//
//            const char *largestring = "Foo Bar Baz";
//            const char *smallstring = "Bar";
//            char *ptr;
//
//            ptr = strnstr(largestring, smallstring, 4);

#include "libft.h" // size_t is defined in header <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
