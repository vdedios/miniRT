/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:21:48 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:11 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		ft_get_parallel_dir(char *option)
{
	char		**buffer;
	int			i;
	t_vector	dir;

	i = 0;
	buffer = ft_split(option, ':');
	while (buffer[i])
		i++;
	if (i != 2)
		ft_error_handler(BAD_BONUS);
	dir = ft_load_coords(buffer[1]);
	ft_normalize_vector(&dir);
	return (dir);
}

t_vector		ft_is_parallel_light(char *option)
{
	t_vector	dir;

	dir = (t_vector){0, 0, 0};
	if (option)
	{
		if (!ft_strncmp(option, "parallel:", 9))
			dir = ft_get_parallel_dir(option);
		else
			ft_error_handler(BAD_BONUS);
	}
	return (dir);
}
