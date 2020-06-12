#include "miniRT.h"

void            ft_check_rgb_range(t_rgb *color)
{
    if (color->r > 255)
        color->r = 255;
    if (color->g > 255)
        color->g = 255;
    if (color->b > 255)
        color->b = 255;
}

int             ft_mix_color(t_rgb shade, t_rgb geometry)
{
    t_rgb color;

    color.r = shade.r * geometry.r / 255;
    color.g = shade.g * geometry.g / 255;
    color.b = shade.b * geometry.b / 255;
    return((color.r << 16) + (color.g << 8) + color.b);
}

t_rgb		ft_shading(t_scene s, t_vector p, t_vector normal, t_vector light)
{
    double	shade;
    t_ray       shadow;
    t_rgb       color;
    double      a0;
    double      a1;

    ft_normalize_vector(&light);
    ft_normalize_vector(&normal);
    shadow.global = light;
    shadow.origin = p;
    shade = ft_dot_product(light, normal);
    if(ft_shadows(s, &shadow) || shade < 0)
        shade = 0;
    a0 = s.ambient.intensity;
    a1 = s.light[0]->intensity;
    color.r = a0 * s.ambient.rgb.r + a1 * shade * s.light[0]->rgb.r;
    color.g = a0 * s.ambient.rgb.g + a1 * shade * s.light[0]->rgb.g;
    color.b = a0 * s.ambient.rgb.b + a1 * shade * s.light[0]->rgb.b;
    ft_check_rgb_range(&color);
    return (color);
}
