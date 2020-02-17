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
	int		R;
	double	x;
	int		y;
	int		r;

	R = 150;
	r = R;
		while (r >= 0)
		{
			y = 0;
			x = r;
			while (y <= x)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x + (int)x, window->y - y, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x + y, window->y - (int)x, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x - y, window->y - (int)x, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x - (int)x, window->y - y, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x - (int)x, window->y + y, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x - y, window->y + (int)x, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x + y, window->y + (int)x, 0x0000FF00);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->x + (int)x, window->y + y, 0x0000FF00);
				y++;
				x = sqrt(pow((double)r, 2.0) - pow((double)y, 2.0)); 
			}
			r--;
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
