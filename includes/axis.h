/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:27:53 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:28:07 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AXIS_H
# define AXIS_H

# include "scene_types.h"

/*
** Auxiliar axes functions
*/

void	ft_draw_center(t_axis_ref axis, t_scene *scene);
void	ft_set_label_pos(t_axis_ref axis, char dir, t_scene *scene);
void	ft_sketch_axis(t_axis_ref *axis, char dir, t_scene *scene);
void	ft_draw_axis(t_vector p, char dir, t_scene *scene);
void	ft_draw_reference(t_matrix c_base, t_scene *scene);

#endif
