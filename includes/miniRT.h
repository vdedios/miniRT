/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:20:40 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/25 19:23:59 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "mlx.h"
#include "miniRT_types.h"
#include "libft.h"
#include "get_next_line.h"


/*
** General functions
*/
int				ft_printf(const char *s, ...);
void            ft_miniRT(t_list *elements);
void			ft_error_handler(int error_id);

/*
** Scene handling functions
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
** Scene handling utils functions
*/
void			ft_del_matrix(char **matrix);
float			ft_ftoi(char *str);
int				ft_rgb_to_hex(char **rgb);

/*
** Scene error handling functions.
** An scene can have 4 types of numeric values: simple int, simple float
** float coordenates, rgb values.
*/
void			ft_check_digit(char *info, char id);
void			ft_load_uint(int *num, char *buffer);
void			ft_load_ufloat(float *num, char *buffer);
void			ft_load_coords(float *coord, char *buffer);
void			ft_load_rgb(int *rgb, char *buffer);

#endif
