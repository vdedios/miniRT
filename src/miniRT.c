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

void            ft_scene_to_screen(t_scene *scene)
{
    //Cuando vara a guardar en bmp hay que modificar esta función ya que de momento
    //sólo muestra por pantalla después de renderizar
    ft_render_scene(scene, scene->i_cam);
    mlx_clear_window(scene->window.mlx_ptr, scene->window.win_ptr);
    mlx_put_image_to_window(scene->window.mlx_ptr, scene->window.win_ptr,
            scene->img.id, 0, 0);
    mlx_string_put(scene->window.mlx_ptr, scene->window.win_ptr,
            scene->axis.x.x, scene->axis.x.y, 0x00FF0000, "x");
    mlx_string_put(scene->window.mlx_ptr, scene->window.win_ptr,
            scene->axis.y.x, scene->axis.y.y, 0x0000FF00, "y");
    mlx_string_put(scene->window.mlx_ptr, scene->window.win_ptr,
            scene->axis.z.x, scene->axis.z.y, 0x000000FF, "z");
}

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
        ft_scene_to_screen(scene);
    }
    else if (key == 124)
    {
        if (scene->i_cam < scene->n_cams - 1)
            scene->i_cam = scene->i_cam + 1;
        else
            scene->i_cam = 0;
        printf("i_cam vale: %d\n", scene->i_cam);
        ft_scene_to_screen(scene);
    } 
    else if (key == 53)
        ft_exit(&scene->window);
    return (0);
}

void            ft_miniRT(t_scene scene)
{
    scene.i_cam = 0;
    scene.window.mlx_ptr = mlx_init();
    scene.window.win_ptr = mlx_new_window(scene.window.mlx_ptr,
            scene.x, scene.y, "miniRT");
    scene.img.id = mlx_new_image(scene.window.mlx_ptr, scene.x, scene.y);
    scene.img.addr = mlx_get_data_addr(scene.img.id, &scene.img.bitpixl,
                &scene.img.len,&scene.img.end);
    mlx_hook(scene.window.win_ptr, 17, 0, ft_exit, &scene.window);
    mlx_key_hook(scene.window.win_ptr, ft_handle_keyboard, &scene);
    ft_scene_to_screen(&scene);
    mlx_loop(scene.window.mlx_ptr);
} 
