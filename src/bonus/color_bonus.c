#include "miniRT.h"

t_vector	ft_wave_normal(t_obj_color obj)
{
    t_vector    wave_n;
    double      alpha;
    double      d;

    d = ft_mod_vector(ft_sub_vector(obj.center, obj.p));
    alpha = 100 * exp(-d * 0.75) * cos(1.5 * M_PI * d);
    wave_n = ft_sub_vector(obj.p, obj.center);
    wave_n.x *= alpha;
    wave_n.y *= alpha;
    wave_n.z = 100;
    ft_normalize_vector(&wave_n);
    return (wave_n);
}

t_rgb           ft_checkered_pattern(t_vector p, t_rgb color)
{
    if ((int)(floor(p.x) + floor(p.y)) % 2)
        return ((t_rgb){255, 255, 255});
    return (color);
}

t_rgb           ft_rainbow_pattern(t_vector n, t_rgb color)
{
    color.r = 255 * ft_abs(n.x);
    color.g = 255 * ft_abs(n.y);
    color.b = 255 * ft_abs(n.z);
    ft_check_rgb_range(&color);
    return (color);
}

t_obj_color     ft_disruption(t_scene s, t_obj_color obj)
{
    if (s.option[1])
        obj.normal = ft_wave_normal(obj);
    if (s.option[2])
        obj.rgb = ft_checkered_pattern(obj.p, obj.rgb);
    if (s.option[3])
        obj.rgb = ft_rainbow_pattern(obj.normal, obj.rgb);
    return (obj);
}
