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

int             close(int key, t_window *window)
{
	if (key == 53)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(0);
	}
	return (0);
}

void			draw_diamond(t_window *window)
{
	int	R;
	int x;
	int y;

	R = 40;
	y = R - 1;
	while (y > -R)
	{
		if (y >= 0)
		{
			x = y - (R - 1);
			while (x <= (R - 1) - y)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x + x, window->y + y, 0x0000FF00);
				x++;
			}
		}
		else
		{
			x = -(R - 1) - y;
			while (x < (R - 1) + y)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x + x, window->y + y, 0x0000FF00);
				x++;
			}
		}
		y--;
	}
}

void			draw_circle(t_window *window)
{
	double	R;
	double	x;
	double	y;
	double	aux_y;
	int		aux_x;

	R = 40.0;
	y = R - 1;
	aux_x = 0;
	while (y > 0)
	{
		aux_y = y;
		x = sqrt(pow(R, 2.0) - pow(y, 2.0));		
		if (aux_x != (int)x)
		{
			while (aux_x < (int)x)
			{
				while (aux_y >= -y)
				{
					mlx_pixel_put(window->mlx_ptr, window->win_ptr, (int)aux_x + window->x, (int)aux_y + window->y, 0x0000FF00);
					mlx_pixel_put(window->mlx_ptr, window->win_ptr, -(int)aux_x + window->x, -(int)aux_y + window->y, 0x0000FF00);
					aux_y--;
				}
				aux_y = y;
				aux_x++;
			}
		}
		aux_y = y;
		while (aux_y >= -y)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, (int)x + window->x, (int)aux_y + window->y, 0x0000FF00);
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, -(int)x + window->x, -(int)aux_y + window->y, 0x0000FF00);
			aux_y--;
		}
		aux_x++;
		y--;
	}
}

int             draw(t_window *window)
{
	if (window->button == 1)
		draw_circle(window);
	return (0);
}

int				button_press(int button, int x, int y, t_window *window)
{
	(void)x;
	(void)y;

	if (button == 1)
		window->button = 1;
	return (0);
}

int				button_release(int button, int x, int y, t_window *window)
{
	(void)x;
	(void)y;

	if (button == 1)
		window->button = 0;
	return (0);
}

int				map_coords(int x, int y, t_window *window)
{
	int i;

	i = 0;
	window->x = x;
	window->y = y;
	i++;
	return (0);
}

void            miniRT()
{
	t_window      window;

	window.button = 0;
	window.x = 0;
	window.y = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 500, 500, "Hello world!");
	mlx_key_hook(window.win_ptr, close, &window);
	mlx_hook(window.win_ptr, 4, 0L, button_press, &window);
	mlx_hook(window.win_ptr, 5, 0L, button_release, &window);

	mlx_hook(window.win_ptr, 6, 0, map_coords, &window);

	mlx_loop_hook(window.mlx_ptr, draw, &window);
	mlx_loop(window.mlx_ptr);
} 
