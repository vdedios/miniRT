/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:29:09 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:30:11 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_TYPES_H
# define BMP_TYPES_H

typedef struct		s_file_header{
	unsigned char	bitmap_type[2];
	unsigned char	file_size[4];
	short			reserved1;
	short			reserved2;
	unsigned char	offset_bits;
	short			reserved3;
}					t_file_header;

typedef struct		s_image_header{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_image_header;

#endif
