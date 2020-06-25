/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:20:24 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:10 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadows(t_scene scene, t_ray *ray)
{
	int	i;

	i = -1;
	while (scene.sphere[++i])
		if (ft_shadow_sphere(scene, ray, i))
			return (1);
	i = -1;
	while (scene.plane[++i])
		if (ft_shadow_plane(scene, ray, i))
			return (1);
	i = -1;
	while (scene.square[++i])
		if (ft_shadow_square(scene, ray, i))
			return (1);
	i = -1;
	while (scene.triangle[++i])
		if (ft_shadow_triangle(scene, ray, i))
			return (1);
	i = -1;
	while (scene.cylinder[++i])
		if (ft_shadow_cylinder(scene, ray, i))
			return (1);
	return (0);
}

int	ft_between_light_source(t_vector light, t_vector point, t_vector origin)
{
	t_vector	shadow_ray;
	t_vector	light_ray;
	double		mod_global;
	double		mod_shadow;

	shadow_ray = ft_sub_vector(point, origin);
	light_ray = ft_sub_vector(light, origin);
	mod_shadow = ft_mod_vector(shadow_ray);
	mod_global = ft_mod_vector(light_ray);
	if (mod_shadow > 0.0001 && mod_shadow < mod_global)
		return (1);
	return (0);
}
