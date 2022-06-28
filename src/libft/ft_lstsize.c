/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:06:41 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:47:48 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_lstsize
// Prototype        | int ft_lstsize(t_list *lst);
// Turn in files    | -
// Parameters       | lst: The beginning of the list.
// Return value     | The length of the list
// External functs. | None
// Description      | Counts the number of nodes in a list.

#include "libft.h" // t_list definition

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
