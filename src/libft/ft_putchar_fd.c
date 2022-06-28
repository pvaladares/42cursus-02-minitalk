/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:48:40 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:52:19 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_putchar_fd
// Prototype        | void ft_putchar_fd(char c, int fd);
// Turn in files    | -
// Parameters       | c: The character to output.
//					| fd: The file descriptor on which to write.
// Return value     | None
// External functs. | write
// Description      | Outputs the character ’c’ to the given file descriptor.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
