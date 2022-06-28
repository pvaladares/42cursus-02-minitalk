/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:51:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:56:40 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_putstr_fd
// Prototype        | void ft_putstr_fd(char *s, int fd);
// Turn in files    | -
// Parameters       | s: The string to output.
//					| fd: The file descriptor on which to write.
// Return value     | None
// External functs. | write
// Description      | Outputs the string ’s’ to the given file descriptor.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}
