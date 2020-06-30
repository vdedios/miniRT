/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:57:33 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/30 11:30:37 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#ifdef __APPLE__

void	ft_check_system_resolution(t_scene *scene)
{
	int	w;
	int	h;

	w = 1000;
	h = 1000;
	if (scene->x > w)
		scene->x = w;
	if (scene->y > h)
		scene->y = h;
}

#else

void	ft_check_system_resolution(t_scene *scene)

	int	w;
	int	h;

	mlx_get_screen_size(scene->window.mlx_ptr, &w, &h);
	if (scene->x > w)
		scene->x = w;
	if (scene->y > h)
		scene->y = h;
}

#endif

int		ft_bonus_option(void)
{
	int	bonus;

	bonus = 0;
	return (bonus);
}
