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

#include "miniRT.h"

int 			ft_exit(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

int             ft_close_win(int key, t_window *window)
{
	if (key == 53)
		ft_exit(window);
	return (0);
}


void            ft_miniRT(t_scene scene)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, scene.x, scene.y, "Hello world!");
	mlx_key_hook(window.win_ptr, ft_close_win, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_exit, &window);
	ft_draw_scene(scene, &window);
	mlx_loop(window.mlx_ptr);
} 
