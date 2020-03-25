/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:17:31 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/25 20:09:48 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT.h"
#include <math.h>

int             ft_close_win(int key, t_window *window)
{
	if (key == 53)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		ft_draw_scene(t_list *elements)
{
	//Aqui empieza el ray tracing
	int x;
	int y;
	(void)elements;

	x = 0;
	y = 0;
	/*kkkk
	while (x < scene->x)
	{
		while (y < scene->y)
		{
			//ft_cam_local_coords();
			y++;
		}
		y = 0;
		x++;
	}
	*/
	return (0);
}

t_scene			*ft_window_info(t_list *elements)
{
	t_scene	*win;

	win = (t_scene *)elements->content;
	/*
	while (win->id != 'R')
	{
		aux = elements->next;
		elements = aux;
		win = elements->content;
	}
	*/
	return (0);
}

void            ft_miniRT(t_list *elements)
{
	t_window	window;

	window.button = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 500, 500, "Hello world!");
	mlx_key_hook(window.win_ptr, ft_close_win, &window);
	mlx_loop_hook(window.mlx_ptr, ft_draw_scene, elements);
	mlx_loop(window.mlx_ptr);
} 
