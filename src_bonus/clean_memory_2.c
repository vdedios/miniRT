/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:08:36 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/25 17:07:19 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_release_textures(t_scene scene, t_bonus bonus)
{
	if (bonus.texture.img)
		mlx_destroy_image(scene.window.mlx_ptr, bonus.texture.img);
	if (bonus.bumpmap.img)
		mlx_destroy_image(scene.window.mlx_ptr, bonus.bumpmap.img);
}

void	ft_clean_cameras(t_camera **camera)
{
	int	i;

	i = 0;
	while (camera[i])
	{
		free(camera[i]);
		camera[i] = NULL;
		i++;
	}
	free(camera[i]);
	camera[i] = NULL;
	free(camera);
	camera = NULL;
}

void	ft_clean_lights(t_light **light)
{
	int	i;

	i = 0;
	while (light[i])
	{
		free(light[i]);
		light[i] = NULL;
		i++;
	}
	free(light[i]);
	light[i] = NULL;
	free(light);
	light = NULL;
}

void	ft_clean_spheres(t_scene scene, t_sphere **sphere)
{
	int	i;

	i = 0;
	while (sphere[i])
	{
		ft_release_textures(scene, sphere[i]->bonus);
		free(sphere[i]);
		sphere[i] = NULL;
		i++;
	}
	free(sphere[i]);
	sphere[i] = NULL;
	free(sphere);
	sphere = NULL;
}

void	ft_clean_planes(t_scene scene, t_plane **plane)
{
	int	i;

	i = 0;
	while (plane[i])
	{
		ft_release_textures(scene, plane[i]->bonus);
		free(plane[i]);
		plane[i] = NULL;
		i++;
	}
	free(plane[i]);
	plane[i] = NULL;
	free(plane);
	plane = NULL;
}
