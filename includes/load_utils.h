/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:42:43 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:43:37 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_UTILS_H
# define LOAD_UTILS_H

# include "scene_types.h"

/*
** Util load functions
*/

void		ft_del_matrix(char **matrix);

/*
** Math util functions
*/

double		ft_ftoi(char *str);
int			ft_rgb_to_hex(char **rgb);
int			ft_load_uint(char *buffer);
double		ft_load_udouble(char *buffer);
t_vector	ft_load_coords(char *buffer);
t_rgb		ft_load_rgb(char *buffer);
void		ft_get_triangle_boundaries(t_triangle *triangle);
void		ft_check_system_resolution(t_scene *scene);
void		ft_check_digit(char *info, char id);

#endif
