#ifndef AXIS_H
# define AXIS_H

#include "scene_types.h"
/*
** Auxiliar axes functions
*/

void	ft_draw_axis(double *p, char axis, t_scene scene, t_window *window);
void	ft_draw_reference(double	**c_base, t_scene scene, t_window *window);

#endif
