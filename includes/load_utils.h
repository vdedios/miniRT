#ifndef LOAD_UTILS_H
# define LOAD_UTILS_H

#include "scene_types.h"

/*
** Util load functions
*/

void			ft_del_matrix(char **matrix);

/*
** Math util functions
*/

double			ft_ftoi(char *str);
int			ft_rgb_to_hex(char **rgb);
void			ft_load_uint(int *num, char *buffer);
void			ft_load_udouble(double *num, char *buffer);
void			ft_load_coords(double *coord, char *buffer);
void			ft_load_rgb(int *rgb, char *buffer);

#endif
