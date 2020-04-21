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

int 		ft_exit(t_window *window)
{
    mlx_destroy_window(window->mlx_ptr, window->win_ptr);
    exit(EXIT_SUCCESS);
}

int             ft_handle_keyboard(int key, t_scene *scene)
{
    if (key == 123)
    {
        if (scene->i_cam > 0)
            scene->i_cam = scene->i_cam - 1;
        else
            scene->i_cam = scene->n_cams - 1;
        //Quizás se pueda pasar solo la escena
        //Calcular todo en un buffer y que draw sea lo que devuelve
        printf("i_cam vale: %d\n", scene->i_cam);
        ft_draw_scene(scene, &scene->window, scene->i_cam);
        mlx_put_image_to_window(scene->window.mlx_ptr, scene->window.win_ptr, scene->img.id, 0, 0);
    }
    else if (key == 124)
    {
        if (scene->i_cam < scene->n_cams - 1)
            scene->i_cam = scene->i_cam + 1;
        else
            scene->i_cam = 0;
        printf("i_cam vale: %d\n", scene->i_cam);
        ft_draw_scene(scene, &scene->window, scene->i_cam);
        mlx_put_image_to_window(scene->window.mlx_ptr, scene->window.win_ptr, scene->img.id, 0, 0);
    } 
    else if (key == 53)
        ft_exit(&scene->window);
    return (0);
}

void            ft_miniRT(t_scene scene)
{
    scene.i_cam = scene.n_cams - 1;
    scene.window.mlx_ptr = mlx_init();
    scene.window.win_ptr = mlx_new_window(scene.window.mlx_ptr, scene.x, scene.y, "miniRT");

    scene.img.id = mlx_new_image(scene.window.mlx_ptr, scene.x, scene.y);
    scene.img.addr = mlx_get_data_addr(scene.img.id, &scene.img.bitpixl,
            &scene.img.len,&scene.img.end);

    mlx_hook(scene.window.win_ptr, 17, 0, ft_exit, &scene.window);
    mlx_key_hook(scene.window.win_ptr, ft_handle_keyboard, &scene);
    ft_draw_scene(&scene, &scene.window, scene.i_cam);
    mlx_put_image_to_window(scene.window.mlx_ptr, scene.window.win_ptr, scene.img.id, 0, 0);
    mlx_loop(scene.window.mlx_ptr);
} 
