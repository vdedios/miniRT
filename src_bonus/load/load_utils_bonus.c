/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:57:33 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/25 13:38:33 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int		ft_bonus_option(void)
{
	int	bonus;

	bonus = 2;
	return (bonus);
}
