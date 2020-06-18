#ifndef PIPELINE_H
# define PIPELINE_H

/*
** Ray tracing pipeline functions
*/

int		ft_render_scene(t_scene *scene);
void		ft_draw_element(t_scene scene, t_ray *ray);

#endif
