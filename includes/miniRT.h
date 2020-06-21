/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:20:40 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/25 19:23:59 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <CoreGraphics/CGDisplayConfiguration.h>
#include "mlx.h"
#include "libft.h"
#include "printf.h"
#include "get_next_line.h"
#include "algebra.h"
#include "axis.h"
#include "camera.h"
#include "error.h"
#include "geometry.h"
#include "geometry_types.h"
#include "load.h"
#include "load_utils.h"
#include "pipeline.h"
#include "scene_types.h"
#include "shadows.h"
#include "color.h"
#include "bmp.h"
#include "bmp_types.h"
#include "minirt_bonus.h"


/*
** Main  functions
*/

void            ft_miniRT(t_scene s);
void            ft_scene_to_screen(t_scene *scene);
int 		ft_exit(t_window *window);

/*
** Utils functions
*/

void            ft_handle_axis_translation(int key, t_scene *s);
void            ft_change_camera(int key, t_scene *s);
int             ft_handle_keyboard(int key, t_scene *s);
int             ft_handle_mouse(int press, int u, int v, t_scene *s);

/*
** Options
*/

void            ft_initialize_options(t_scene *scene);
void            ft_save_option(char *argv, t_scene *scene);
void            ft_check_options(int argc, char **argv, t_scene *scene);

#endif
