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

#include "mlx.h"
#include "libft.h"
#include "printf.h"
#include "get_next_line.h"

#include "scene_types.h"
#include "geometry_types.h"
#include "algebra.h"
#include "load_data.h"

/*
** General functions
*/

void            ft_miniRT(t_scene scene);

/*
** Scene drawing functions
*/

int		ft_draw_scene(t_scene scene, t_window *window);
double	**ft_global_camera_base(t_scene scene);
double	*ft_local_camera_ray(t_scene scene, int p_x, int p_y);

#endif
