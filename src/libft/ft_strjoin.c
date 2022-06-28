/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:31:10 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:01:51 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_strjoin
// Prototype        | char *ft_strjoin(char const *s1, char const *s2);
// Turn in files    | -
// Parameters       | s1: The prefix string.
//					| s2: The suffix string.
// Return value     | The new string.
//					| NULL if the allocation fails.
// External functs. | malloc
// Description      | Allocates (with malloc(3)) and returns a new string, 
//					| which is the result of the concatenation of ’s1’ and ’s2’.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
