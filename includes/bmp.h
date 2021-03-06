/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:28:23 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:28:27 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "bmp_types.h"

void	ft_convert_buffer_to_bmp(int fd, t_scene scene);
void	ft_scene_to_bmp(t_scene scene);
void	ft_image_header(t_scene scene, int fd);
void	ft_file_header(t_scene scene, int fd);

#endif
