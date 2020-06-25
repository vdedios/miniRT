/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:08:36 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/25 16:46:59 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_clean_squares(t_scene scene, t_square **square)
{
	int	i;

	i = 0;
	while (square[i])
	{
		ft_release_textures(scene, square[i]->bonus);
		free(square[i]);
		square[i] = NULL;
		i++;
	}
	free(square[i]);
	square[i] = NULL;
	free(square);
	square = NULL;
}

void	ft_clean_triangles(t_scene scene, t_triangle **triangle)
{
	int	i;

	i = 0;
	while (triangle[i])
	{
		ft_release_textures(scene, triangle[i]->bonus);
		free(triangle[i]);
		triangle[i] = NULL;
		i++;
	}
	free(triangle[i]);
	triangle[i] = NULL;
	free(triangle);
	triangle = NULL;
}

void	ft_clean_cylinders(t_cylinder **cylinder)
{
	int i;

	i = 0;
	while (cylinder[i])
	{
		free(cylinder[i]);
		cylinder[i] = NULL;
		i++;
	}
	free(cylinder[i]);
	cylinder[i] = NULL;
	free(cylinder);
	cylinder = NULL;
}

void	ft_clean_memory(t_scene scene)
{
	ft_clean_cameras(scene.camera);
	ft_clean_lights(scene.light);
	ft_clean_spheres(scene, scene.sphere);
	ft_clean_planes(scene, scene.plane);
	ft_clean_squares(scene, scene.square);
	ft_clean_triangles(scene, scene.triangle);
	ft_clean_cylinders(scene.cylinder);
}
