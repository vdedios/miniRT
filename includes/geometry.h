#ifndef GEOMETRY_H
# define GEOMETRY_H

#include "scene_types.h"

/*
** Geometry functions
*/

int             ft_intersect_sphere(t_scene *s, t_ray *r, int i);
int		ft_draw_sphere(t_scene s, t_ray *r, int i);

int		ft_draw_plane(t_scene s, t_ray *r, int i);
int		ft_intersect_plane(t_scene *s, t_auxplane *plane, t_ray *r);
int             ft_get_point_plane(t_scene *s, t_auxplane *plane, t_ray *r);

int		ft_draw_square(t_scene s, t_ray *r, int i);

int		ft_draw_triangle(t_scene s, t_ray *r, int i);

int		ft_draw_cylinder(t_scene s, t_ray *r, int i);

#endif
