#ifndef BMP_H
# define BMP_H

#include "bmp_types.h"

void	ft_image_header(t_image_header *bih, t_scene scene);
void    ft_file_header(t_file_header *bfh, int file_size);
void    ft_convert_buffer_to_bmp(int fd, t_scene scene);
void    ft_scene_to_bmp(t_scene scene);

#endif
