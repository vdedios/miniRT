/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:31:24 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:31:32 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

void		ft_check_rgb_range(t_rgb *color);
t_rgb		ft_mix_color(t_rgb amb, t_rgb spot);
t_rgb		ft_ambient(t_scene s, t_obj_color obj);
t_rgb		ft_spot_light(t_scene s, t_obj_color obj);
int			ft_get_color(t_scene s, t_obj_color obj);
t_vector	ft_wave_normal(t_obj_color obj);

#endif
