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
#include "mlx.h"
#include "miniRT_types.h"
#include "libft.h"
#include "get_next_line.h"

int				ft_printf(const char *s, ...);
void			ft_miniRT();

/*
** Scene handling functions
*/
int				ft_load_scene(char	*path, t_scene *scene);
int				ft_load_element(char *line, t_scene *scene);
int				ft_load_resolution(char *line, t_scene *scene);
void			ft_del_matrix(char **matrix);
int				ft_check_digit(char *info, char id);

#endif
