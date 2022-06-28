/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:53 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 17:07:40 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_lstclear
// Prototype        | void ft_lstclear(t_list **lst, void (*del)(void *));
// Turn in files    | -
// Parameters       | lst: The address of a pointer to a node.
//					| del: The address of the function used to delete the 
//					| content of the node.
// Return value     | None
// External functs. | free
// Description      | Deletes and frees the given node and every successor of 
//					| that node, using the function ’del’ and free(3).
//					| Finally, the pointer to the list must be set to NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
