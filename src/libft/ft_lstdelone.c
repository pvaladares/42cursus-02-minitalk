/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:53 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 17:23:31 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_lstdelone
// Prototype        | void ft_lstdelone(t_list *lst, void (*del)(void *));
// Turn in files    | -
// Parameters       | lst: The node to free.
//					| del: The address of the function used to delete the 
//					| content.
// Return value     | None
// External functs. | free
// Description      | Takes as a parameter a node and frees the memory of the 
//					| node’s content using the function ’del’ given as a 
//					| parameter and free the node.
//					| The memory of ’next’ must not be freed.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
