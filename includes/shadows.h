#ifndef SHADOWS_H
# define SHADOWS_H

/*
** General shadow functions
*/
int             ft_shadows(t_scene scene, t_ray *ray);
int             ft_between_light_source(t_vector light,
                    t_vector point, t_vector origin);

/*
** Geometry shadow functions
*/
int             ft_shadow_cylinder(t_scene s, t_ray *r, int i);
int             ft_shadow_plane(t_scene s, t_ray *r, int i);
int		ft_intersect_shadow_plane(t_auxplane *plane, t_ray *r);
int             ft_shadow_sphere(t_scene s, t_ray *r, int i);
int             ft_shadow_square(t_scene s, t_ray *r, int i);
int		ft_shadow_triangle(t_scene s, t_ray *r, int i);

#endif
