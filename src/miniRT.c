/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:17:31 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/25 19:34:10 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl/mlx.h"
#include "../header/miniRT.h"

int             close(int keycode, t_window *window)
{
	printf("TECLA!: %d\n", keycode);
	if (keycode ==53)
    	mlx_destroy_window(window->mlx, window->win);
	return (0);
}

void            miniRT()
{
    t_window      window;

    window.mlx = mlx_init();
	while (1)
	{
 		window.win = mlx_new_window(window.mlx, 1920, 1080, "Hello world!");
    	mlx_key_hook(window.win, close, &window);
	}
} 
