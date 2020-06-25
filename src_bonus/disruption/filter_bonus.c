/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:51:37 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:11 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			ft_render_pxl_antialiasing(double px, double py
					, t_ray *ray, t_scene *s)
{
	int		i;
	int		j;
	t_rgb	color;

	color = (t_rgb){0, 0, 0};
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			ft_render_pxl(px + (i + 0.5) / 2, py + (j + 0.5) / 2, ray, s);
			color.r += (ray->color & 0x00ff0000) >> 16;
			color.g += (ray->color & 0x0000ff00) >> 8;
			color.b += (ray->color & 0x000000ff);
			j++;
		}
		i++;
	}
	ray->color = ((int)(color.r / 4) << 16)
		+ ((int)(color.g / 4) << 8) + (int)(color.b / 4);
}

t_rgb			ft_sepia_filter(t_scene s, t_rgb in_color)
{
	t_rgb	out_color;

	if (s.option[2])
	{
		out_color.r = (in_color.r * 0.393)
			+ (in_color.g * 0.769) + (in_color.b * 0.189);
		out_color.g = (in_color.r * 0.349)
			+ (in_color.g * 0.686) + (in_color.b * 0.168);
		out_color.b = (in_color.r * 0.272)
			+ (in_color.g * 0.534) + (in_color.b * 0.131);
		ft_check_rgb_range(&out_color);
		return (out_color);
	}
	return (in_color);
}
