#ifndef CAMERA_H
# define CAMERA_H

#include "scene_types.h"

/*
** Camera functions
*/

t_vector        ft_local_camera_ray(t_scene s, int p_x, int p_y);
void	        ft_global_camera_base(t_scene *scene, int i_cam);

#endif
