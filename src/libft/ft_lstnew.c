/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:23:44 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 16:55:52 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_lstnew
// Prototype        | t_list *ft_lstnew(void *content);
// Turn in files    | -
// Parameters       | content: The content to create the node with.
// Return value     | The new node
// External functs. | malloc
// Description      | Allocates (with malloc(3)) and returns a new node.
// 					| The member variable ’content’ is initialized with
//					| the value of the parameter ’content’. The variable
//					| ’next’ is initialized to NULL.

#include "libft.h" // t_list and NULL definitions

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
