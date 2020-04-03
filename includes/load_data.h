#ifndef LOAD_DATA_H
# define LOAD_DATA_H

/*
** Main scene data handling functions
*/

void			ft_load_scene(char	*path, t_scene *scene);
void			ft_load_element(char *line, t_scene *scene);
void			ft_load_resolution(char *line, t_scene *scene);
void			ft_load_ambient(char *line, t_scene *scene);
void			ft_load_camera(char *line, t_scene *scene);
void			ft_load_light(char *line, t_scene *scene);
void			ft_load_sphere(char *line, t_scene *scene);
void			ft_load_plane(char *line, t_scene *scene);
void			ft_load_square(char *line, t_scene *scene);
void			ft_load_cylinder(char *line, t_scene *scene);
void			ft_load_triangle(char *line, t_scene *scene);

/*
** Util load functions
*/

void			ft_del_matrix(char **matrix);

/*
** Math functions
*/

double			ft_ftoi(char *str);
int				ft_rgb_to_hex(char **rgb);
void			ft_load_uint(int *num, char *buffer);
void			ft_load_udouble(double *num, char *buffer);
void			ft_load_coords(double *coord, char *buffer);
void			ft_load_rgb(int *rgb, char *buffer);

/*
** Scene error handling functions.
*/

void			ft_error_handler(int error_id);
void			ft_check_digit(char *info, char id);

#endif
