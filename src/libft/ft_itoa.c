/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:28:34 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:39:54 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_itoa
// Prototype        | char *ft_itoa(int n);
// Turn in files    | -
// Parameters       | n: the integer to convert.
// Return value     | The string representing the integer. 
//					| NULL if the allocation fails.
// External functs. | malloc
// Description      | Allocates (with malloc(3)) and returns a string 
//					| representing the integer received as an argument. 
//					| Negative numbers must be handled.

#include "libft.h" // size_t is defined in header <stdlib.h>

// Function returns the length of a number, including the '-' sign
static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

// Function takes an 'int' and converts it to a null-terminated string
char	*ft_itoa(int nbr)
{
	char	*str;
	long	nb;
	int		i;

	nb = nbr;
	i = ft_len(nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}
