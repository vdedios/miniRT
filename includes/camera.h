#ifndef CAMERA_H
# define CAMERA_H

#include "scene_types.h"

/*
** Camera functions
*/

t_vector        ft_local_camera_ray(t_scene s, double p_x, double p_y);
int	        ft_global_camera_base(t_scene *scene, int i_cam);

#endif
