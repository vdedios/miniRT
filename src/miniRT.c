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

#include "../minilibx_opengl/mlx.h"
#include "../include/miniRT.h"

int             close(int keycode, int x, int y, t_window *window)
{
	printf("X:%d Y:%d\n", x, y);
	if (keycode == 2)
    	mlx_destroy_window(window->mlx, window->win);
	return (0);
}

void            miniRT()
{
    t_window      window;

    window.mlx = mlx_init();
 	window.win = mlx_new_window(window.mlx, 500, 500, "Hello world!");
    mlx_mouse_hook(window.win, close, &window);
	mlx_loop(window.mlx);
} 
