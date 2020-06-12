#ifndef GEOMETRY_H
# define GEOMETRY_H

#include "scene_types.h"

/*
** Cylinder
*/

void            ft_calc_surface_cylinder(t_scene *s, t_ray *r, int i);
int		ft_intersect_cylinder(t_scene *s, t_ray *r, int i);
int             ft_draw_caps(t_scene s, t_ray *r, int i);
int		ft_draw_cylinder(t_scene s, t_ray *r, int i);
int             ft_intersect_caps(t_scene *s, t_ray *r, int i, t_auxplane *auxplane);
int             ft_shadow_caps(t_scene s, t_ray *r, int i);
void		ft_color_cylinder(t_scene s, t_ray *r, int i);

/*
** Plane
*/

int		ft_intersect_plane(t_scene *s, t_auxplane *plane, t_ray *r);
int             ft_get_point_plane(t_scene *s, t_auxplane *plane, t_ray *r);
int		ft_draw_plane(t_scene s, t_ray *r, int i);

/*
** Sphere
*/

int             ft_intersect_sphere(t_scene *s, t_ray *r, int i);
int		ft_draw_sphere(t_scene s, t_ray *r, int i);

/*
** Square
*/

int		ft_intersect_inside_square(t_scene s,  t_auxplane *auxplane, int i);
int		ft_draw_square(t_scene s, t_ray *r, int i);

/*
** Triangle
*/

double          ft_get_p_param(t_scene s,  t_vector p0,  int i);
double          ft_get_q_param(t_scene s,  t_vector p0,  int i);
int		ft_is_inside_triangle(t_scene s,  t_auxplane *auxplane, int i);
int             ft_intersect_triangle(t_scene *s, t_ray *r, int i,
                t_auxplane *auxplane);
int		ft_draw_triangle(t_scene s, t_ray *r, int i);

#endif
