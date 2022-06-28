/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:37:13 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/09 11:46:12 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function name    | ft_putchar
// Prototype        | int ft_putchar(char c);
// Parameters       | c: The character to output.
// Return value     | Number of chars written
// External functs. | write
// Description      | Outputs the character ’c’ to the stdout.
//
/* From READ(2)
 *
 * RETURN VALUES
 *    Upon successful completion the number of bytes which were
 *    written is returned.  Otherwise, a -1 is returned and the
 *    global variable errno is set to indicate the error."
 */
int	ft_putchar(char c)
{
	int			ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		exit (-1);
	return (ret);
}
