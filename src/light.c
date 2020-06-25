/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:41:14 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:09 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		ft_parallel_light(t_light *light, t_obj_color obj)
{
	t_vector	light_dir;
	t_vector	lp;

	lp = ft_sub_vector(light->pos, obj.p);
	if (ft_isvoid(light->parallel))
	{
		light_dir = light->parallel;
		light_dir = ft_k_vct_prod(-1, light_dir);
		ft_normalize_vector(&light_dir);
		light->pos_shadow = ft_k_vct_prod(ft_dot_product(light_dir, lp)
				, light_dir);
	}
	else
	{
		light_dir = lp;
		light->pos_shadow = light->pos;
		ft_normalize_vector(&light_dir);
	}
	return (light_dir);
}
