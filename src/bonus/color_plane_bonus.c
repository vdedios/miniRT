#include "miniRT.h"

t_vector	ft_wave_normal(t_obj_color obj)
{
    t_vector    wave_n;
    double      alpha;
    double      d;

    wave_n = ft_sub_vector(obj.center, obj.p);
    if (obj.bonus.type == 's')
    {
        d = ft_mod_vector(wave_n) * ft_dot_product(wave_n, (t_vector){0,0,1});
        alpha = 100 * exp(-d * 0.5) * cos(0.25 * M_PI * d);
    }
    else
    {
        d = ft_mod_vector(wave_n);
        alpha = 100 * exp(-d * 0.025) * cos(0.025 * M_PI * d);
    }
    wave_n = ft_sub_vector(obj.p, obj.center);
    wave_n.x *= alpha;
    wave_n.y *= alpha;
    wave_n.z = 100;
    ft_normalize_vector(&wave_n);
    return (wave_n);
}

t_rgb           ft_checkered_pattern(t_obj_color obj)
{
    if (ft_dot_product(obj.normal, (t_vector){0, 0, 1}))
        if ((int)(floor(obj.p.x) + floor(obj.p.y)) % 2)
            return ((t_rgb){255, 255, 255});
    if (ft_dot_product(obj.normal, (t_vector){1, 0, 0}))
        if ((int)(floor(obj.p.z) + floor(obj.p.y)) % 2)
            return ((t_rgb){255, 255, 255});
    if (ft_dot_product(obj.normal, (t_vector){0, 1, 0}))
        if ((int)(floor(obj.p.x) + floor(obj.p.z)) % 2)
            return ((t_rgb){255, 255, 255});
    return (obj.rgb);
}

t_rgb           ft_color_texture(t_obj_color obj, int x, int y)
{
    int                 color;
    t_rgb               rgb;

    color = obj.bonus.texture.val[y * obj.bonus.texture.width + x];
    rgb.r = (color & 0x00FF0000) >> 16;
    rgb.g = (color & 0x0000FF00) >> 8;
    rgb.b = (color & 0x000000FF);
    return (rgb);
}

t_rgb           ft_plane_texture(t_obj_color obj)
{
    int                 x;
    int                 y;

    if (ft_abs(ft_dot_product(obj.normal, (t_vector){1, 0, 0})) == 1)
        x = ft_abs((int)obj.p.z % obj.bonus.texture.width);
    else
        x = ft_abs((int)obj.p.x % obj.bonus.texture.width);
    if (ft_abs(ft_dot_product(obj.normal, (t_vector){0, 1, 0})) == 1)
        y = (obj.bonus.texture.height - 1) - ft_abs((int)obj.p.z
                % obj.bonus.texture.height);
    else
        y = (obj.bonus.texture.height - 1) - ft_abs((int)obj.p.y
                % obj.bonus.texture.height);
    return (ft_color_texture(obj, x, y));
}
