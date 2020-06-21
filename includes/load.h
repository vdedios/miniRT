#ifndef LOAD_H
# define LOAD_H

#include "scene_types.h"

/*
** Main scene data handling functions
*/

void			ft_number_elements(char *line, t_scene *scene);
void			ft_set_elements(t_scene *scene);
void			ft_count_elements(char  *path, t_scene *scene);
void			ft_load_element(char *line, t_scene *scene);
void			ft_load_scene(char      *path, t_scene *scene);
void			ft_load_resolution(char *line, t_scene *scene);
void			ft_load_ambient(char *line, t_scene *scene);
void			ft_load_camera(char *line, t_scene *scene);
void			ft_load_light(char *line, t_scene *scene);
void			ft_load_sphere(char *line, t_scene *scene);
void			ft_load_plane(char *line, t_scene *scene);
void			ft_load_square(char *line, t_scene *scene);
void			ft_load_cylinder(char *line, t_scene *scene);
void			ft_load_triangle(char *line, t_scene *scene);
int                     ft_bonus_option(void);

#endif
