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

/*
** General functions
*/

void            ft_miniRT(t_scene scene);

/*
** Window handling functions
*/

int		ft_draw_scene(t_scene scene, t_window *window);

#endif
