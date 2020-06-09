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
int                     ft_load_uint(char *buffer);
void			ft_load_udouble(double *num, char *buffer);
double                  ft_load_udouble(char *buffer);
t_vector                ft_load_coords(char *buffer);
t_rgb                   ft_load_rgb(char *buffer);


#endif
