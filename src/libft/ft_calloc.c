/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:11:42 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:37:10 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MALLOC(3)                 Library Functions Manual                MALLOC(3)
//
// NAME
//      calloc – memory allocation
//
// SYNOPSIS
//      #include <stdlib.h>
//
//      void *
//      calloc(size_t count, size_t size);
//
//      void
//      free(void *ptr);
//
// DESCRIPTION
//      The malloc() function allocates memory.  
//		The allocated memory is aligned such that it can be 
//		used for any data type, including AltiVec- and SSE-related types.  
//		The free() function frees allocations that were created 
//		via the preceding allocation functions.
//
//      The calloc() function contiguously allocates enough space for count 
//		objects that are size bytes of memory each and returns a pointer to 
//		the allocated memory.  
//		The allocated memory is filled with bytes of value zero.
//
//      The free() function deallocates the memory allocation pointed to 
//		by ptr. 
//		If ptr is a NULL pointer, no operation is performed.
//
// RETURN VALUES
//      If successful, calloc() function returns a pointer to allocated memory.
//		If there is an error, they return a NULL pointer and set errno to 
//		ENOMEM.
//
//      The free() function does not return a value.
//
// DEBUGGING ALLOCATION ERRORS
//      A number of facilities are provided to aid in debugging allocation 
//		errors in applications.  
//		These facilities are primarily controlled via environment variables.
//      The recognized environment variables and their meanings are documented
//		 below.
//
// ENVIRONMENT
//      The following environment variables change the behavior of the 
//		allocation-related functions.
//
//		(...)

#include "libft.h" // size_t is defined in header <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*dst;

	total_size = size * count;
	dst = malloc(total_size);
	if (!dst)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memset(dst, 0, total_size);
	return (dst);
}
