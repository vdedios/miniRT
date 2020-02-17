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

typedef struct	s_window {
    void		*mlx_ptr;
    void		*win_ptr;
	int			button;
	int			x;
	int			y;
}				t_window;

void	miniRT();

#endif
