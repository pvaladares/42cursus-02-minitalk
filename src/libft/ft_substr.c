/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:03:39 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:31:34 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_substr
// Prototype        | char *ft_substr(char const *s, unsigned int start, 
//					| size_t len);
// Turn in files    | -
// Parameters       | s: The string from which to create the substring. 
//					| start: The start index of the substring in the string ’s’.
//					| len: The maximum length of the substring.
// Return value     | The substring.
//					| NULL if the allocation fails.
// External functs. | malloc
// Description      | Allocates (with malloc(3)) and returns a substring from
//					| the string ’s’.
//					| The substring begins at index ’start’ and is of maximum 
//					| size ’len’.

#include "libft.h" // size_t is defined in header <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*dest;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i] && i < len)
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
