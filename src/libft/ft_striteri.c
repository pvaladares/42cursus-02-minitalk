/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:36:51 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:01:30 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_striteri
// Prototype        | void ft_striteri(char *s, void (*f)(unsigned int, char*));
// Turn in files    | -
// Parameters       | s: The string on which to iterate.
//					| f: The function to apply to each character.
// Return value     | None
// External functs. | None
// Description      | Applies the function ’f’ on each character of the string 
//					| passed as argument, passing its index as first argument. 
//					| Each character is passed by address to ’f’ to be modified
//					| if necessary.

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
