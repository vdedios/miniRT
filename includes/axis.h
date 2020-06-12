#ifndef AXIS_H
# define AXIS_H

#include "scene_types.h"
/*
** Auxiliar axes functions
*/

void    ft_draw_center(t_axis_ref axis, t_scene *scene);
void	ft_set_label_pos(t_axis_ref axis, char dir, t_scene *scene);
void    ft_sketch_axis(t_axis_ref *axis, char dir, t_scene *scene);
void	ft_draw_axis(t_vector p, char dir, t_scene *scene);
void	ft_draw_reference(t_matrix c_base, t_scene *scene);

#endif
