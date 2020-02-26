/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:07:42 by vde-dios          #+#    #+#             */
/*   Updated: 2019/11/18 13:09:58 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the character c to given file descriptor.
**
** *In short, the file descriptor is the gateway
** into the kernel's abstractions of underlying
** hardware
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
