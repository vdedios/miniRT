#ifndef PIPELINE_H
# define PIPELINE_H

/*
** Ray tracing pipeline functions
*/

int		ft_draw_scene(t_scene *scene, t_window *window, int i_cam);
int		ft_shading(double *v, double *u);

#endif
