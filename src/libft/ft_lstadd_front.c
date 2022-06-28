/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:50:50 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 17:17:43 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_lstadd_front
// Prototype        | void ft_lstadd_front(t_list **lst, t_list *new);
// Turn in files    | -
// Parameters       | lst: The address of a pointer to the first link of a 
//					| list.
//					| new: The address of a pointer to the node to be added to
//					| the list.
// Return value     | None
// External functs. | None
// Description      | Adds the node ’new’ at the beginning of the list.

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
