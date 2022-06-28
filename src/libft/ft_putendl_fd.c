/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:06:42 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:52:24 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_putendl_fd
// Prototype        | void ft_putendl_fd(char *s, int fd);
// Turn in files    | -
// Parameters       | s: The string to output.
//					| fd: The file descriptor on which to write.
// Return value     | None
// External functs. | write
// Description      | Outputs the string ’s’ to the given file descriptor 
//					| followed by a newline.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
