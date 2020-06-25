/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:25:08 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:25:10 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

/*
** General color disruption
*/

t_obj_color		ft_disruption(t_light *light, t_obj_color obj);

/*
** Filter color
*/

void			ft_render_pxl_antialiasing(double px, double py, t_ray *ray
					, t_scene *s);
t_rgb			ft_sepia_filter(t_scene s, t_rgb in_color);

/*
** Plane disruption
*/

t_vector		ft_wave_normal(t_obj_color obj);
t_rgb			ft_checkered_pattern(t_obj_color obj);
t_rgb			ft_color_texture(t_obj_color obj, int x, int y);
t_rgb			ft_plane_texture(t_obj_color obj);

/*
** Sphere disruption
*/

void			ft_sphere_coords(t_obj_color obj, double *x, double *y);
t_rgb			ft_sphere_texture(t_obj_color obj);
t_rgb			ft_rainbow_pattern(t_vector n, t_rgb color);

/*
** Light disruption
*/

t_vector		ft_parallel_light(t_light *light, t_obj_color obj);

/*
** Color utils
*/

t_vector		ft_bumpmap(t_obj_color obj);
t_vector		ft_get_bumpmap_normal(t_obj_color obj, int x, int y);

/*
** Load bonus
*/

t_texture		ft_load_texture(t_scene *s, char *option);
t_bonus			ft_plane_bonus(t_scene *s, char **option);
t_bonus			ft_sphere_bonus(t_scene *s, char **option);
t_bonus			ft_cylinder_bonus(char **option);
t_vector		ft_get_parallel_dir(char *option);
t_vector		ft_is_parallel_light(char *option);
void			ft_bonus_options_added(char *argv, t_scene *scene);
void			ft_bonus_options(char *argv, t_scene *scene);

#endif
