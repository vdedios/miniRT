#ifndef GEOMETRY_H
# define GEOMETRY_H

#include "scene_types.h"

/*
** Geometry functions
*/

int		ft_draw_sphere(t_scene s, t_ray *r);
int		ft_draw_plane(t_scene s, t_ray *r);
int		ft_draw_square(t_scene s, t_ray *r);
int		ft_draw_triangle(t_scene s, t_ray *r);
int		ft_draw_cylinder(t_scene s, t_ray *r);

#endif
