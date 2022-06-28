/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:39:58 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:53:09 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_lstlast
// Prototype        | t_list *ft_lstlast(t_list *lst);
// Turn in files    | -
// Parameters       | lst: The beginning of the list.
// Return value     | Last node of the list
// External functs. | None
// Description      | Returns the last node of the list.

#include "libft.h" // t_list and NULL definitions

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
