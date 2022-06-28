/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:09:39 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/10 15:56:17 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name    | ft_putnbr_fd
// Prototype        | void ft_putnbr_fd(int n, int fd);
// Turn in files    | -
// Parameters       | n: The integer to output.
//					| fd: The file descriptor on which to write.
// Return value     | None
// External functs. | write
// Description      | Outputs the integer ’n’ to the given file descriptor.

#include "libft.h"

// INT_MIN = -2147483648
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
			write(fd, &"0123456789"[n % 10], 1);
	}
}
