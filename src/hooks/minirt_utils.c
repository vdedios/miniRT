/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:39:15 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/26 15:45:24 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			ft_handle_axis_translation(int key, t_scene *s)
{
	t_vector	aux;

	if (key == KEY_A)
		aux = (t_vector){-1, 0, 0};
	else if (key == KEY_D)
		aux = (t_vector){1, 0, 0};
	else if (key == KEY_W)
		aux = (t_vector){0, 1, 0};
	else if (key == KEY_S)
		aux = (t_vector){0, -1, 0};
	else if (key == KEY_E)
		aux = (t_vector){0, 0, -1};
	else
		aux = (t_vector){0, 0, 1};
	aux = ft_mtx_vct_prod(s->camera[s->i_cam]->base, aux);
	s->camera[s->i_cam]->pos = ft_add_vector(aux, s->camera[s->i_cam]->pos);
	ft_scene_to_screen(s);
}

void			ft_change_camera(int key, t_scene *s)
{
	if (key == ARROW_LEFT)
	{
		if (s->i_cam > 0)
			s->i_cam = s->i_cam - 1;
		else
			s->i_cam = s->n_cams - 1;
	}
	else
	{
		if (s->i_cam < s->n_cams - 1)
			s->i_cam = s->i_cam + 1;
		else
			s->i_cam = 0;
	}
	ft_scene_to_screen(s);
}

int				ft_handle_keyboard(int key, t_scene *s)
{
	if (key == ESC)
		ft_exit(&s->window);
	else if (key == KEY_A || key == KEY_W || key == KEY_S
			|| key == KEY_D || key == KEY_E || key == KEY_Q)
		ft_handle_axis_translation(key, s);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		ft_change_camera(key, s);
	return (0);
}

int				ft_handle_mouse(int press, int u, int v, t_scene *s)
{
	t_vector	new_normal;

	(void)press;
	new_normal = ft_local_camera_ray(*s, (double)u, (double)v);
	new_normal = ft_mtx_vct_prod(s->camera[s->i_cam]->base, new_normal);
	ft_normalize_vector(&new_normal);
	s->camera[s->i_cam]->n = new_normal;
	ft_scene_to_screen(s);
	return (0);
}
