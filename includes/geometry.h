#ifndef GEOMETRY_H
# define GEOMETRY_H

#include "scene_types.h"

/*
** Geometry functions
*/

int		ft_draw_sphere(t_scene s, t_ray *r);
int		ft_draw_plane(double *c_ray, t_scene scene, int *color);
int		ft_draw_square(double *c_ray, t_scene scene, int *color);
int		ft_draw_triangle(double *c_ray, t_scene scene, int *color);
int		ft_draw_cylinder(double *c_ray, t_scene scene, int *color);

#endif
