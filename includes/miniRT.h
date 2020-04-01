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
#include <math.h>
#include "mlx.h"
#include "miniRT_types.h"
#include "libft.h"
#include "get_next_line.h"


/*
** General functions
*/

int				ft_printf(const char *s, ...);
void            ft_miniRT(t_scene scene);

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
double			ft_ftoi(char *str);
int				ft_rgb_to_hex(char **rgb);

/*
** Scene error handling functions.
** An scene can have 4 types of numeric values: simple int, simple double
** double coordenates, rgb values.
*/

void			ft_error_handler(int error_id);
void			ft_check_digit(char *info, char id);
void			ft_load_uint(int *num, char *buffer);
void			ft_load_udouble(double *num, char *buffer);
void			ft_load_coords(double *coord, char *buffer);
void			ft_load_rgb(int *rgb, char *buffer);

/*
** Scene drawing functions
*/
int		ft_draw_scene(t_scene scene, t_window *window);
double	**ft_global_camera_base(t_scene scene);
double	*ft_local_camera_ray(t_scene scene, int p_x, int p_y);

/*
** Auxiliar math functions
*/

double	*ft_cross_product(double *u, double *v);
double	ft_dot_product(double *u, double *v);
void	ft_normalise_vector(double *v);
double	*ft_mtx_vct_prod(double **m, double *v, t_scene scene);
double	*ft_sub_vector(double *u, double *v);
double	*ft_add_vector(double *u, double *v);
double	ft_mod_vector(double *v);
double	*ft_k_vct_prod(double k, double *v);
double	ft_abs(double num);
double	**ft_inv_matrix(double	**m);
double	ft_det(double	**m);
int		ft_minus_vector(double *v);
double	*ft_set_axis(char axis);

#endif
