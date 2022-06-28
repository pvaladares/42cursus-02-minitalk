/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:23:05 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:39:20 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_strtrim
// Prototype        | char *ft_strtrim(char const *s1, char const *set);
// Turn in files    | -
// Parameters       | s1: The string to be trimmed.
//					| set: The reference set of characters to trim.
// Return value     | The trimmed string.
//					| NULL if the allocation fails.
// External functs. | malloc
// Description      | Allocates (with malloc(3)) and returns a copy of ’s1’
//					| with the characters specified in ’set’ removed from the 
//					| beginning and the end of the string.

#include "libft.h" // size_t is defined in header <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
