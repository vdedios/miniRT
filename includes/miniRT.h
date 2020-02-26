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
#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"

typedef struct	s_window {
    void		*mlx_ptr;
    void		*win_ptr;
	int			button;
	int			x;
	int			y;
}				t_window;

typedef struct	s_scene {
}				t_scene;


int				ft_printf(const char *s, ...);
void			ft_miniRT();
void			ft_scene_handler(char *scene_info, t_scene scene);

#endif
