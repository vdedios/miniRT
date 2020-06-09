#ifndef COLOR_H
# define COLOR_H

void            ft_check_rgb_range(t_rgb *color);
int             ft_mix_color(t_rgb shade, t_rgb geometry);
t_rgb		ft_shading(t_scene s, t_vector p, t_vector v, t_vector u);

#endif
