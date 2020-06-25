/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:30:28 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:30:47 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "scene_types.h"

/*
** Camera functions
*/

t_vector	ft_local_camera_ray(t_scene s, double p_x, double p_y);
int			ft_global_camera_base(t_scene *scene, int i_cam);

#endif
