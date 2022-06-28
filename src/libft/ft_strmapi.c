/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:23:44 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:15:24 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_strmapi
// Prototype        | char *ft_strmapi(char const *s, char (*f)(unsigned int, 
//					| char));
// Turn in files    | -
// Parameters       | s: The string on which to iterate.
//					| f: The function to apply to each character.
// Return value     | The string created from the successive applications of
//					|  ’f’. Returns NULL if the allocation fails.
// External functs. | malloc
// Description      | Applies the function ’f’ to each character of the string 
//					| ’s’, and passing its index as first argument to create a
//					| new string (with malloc(3)) resulting from successive 
//					| applications of ’f’.

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
