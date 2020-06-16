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

t_vector        ft_bumpmap(t_scene s, t_obj_color obj)
{
    //Revisar código para que se adapte mejor a las texturas
    double      coef[2];
    int         x;
    int         y;
    t_vector    u;
    t_vector    v;

    x = ft_abs((int)obj.p.x % s.texture.width);
    y = (s.texture.height - 1) - ft_abs((int)obj.p.y % s.texture.height);
    if ((x - 1) >= 0 && (x + 1) < s.texture.width)
        coef[0] = (s.texture.val[y * s.texture.width + (x + 1)]
                - s.texture.val[y * s.texture.width + (x - 1)]) / 2;
    if ((y - 1) >= 0 && (y + 1) < s.texture.height)
        coef[1] = (s.texture.val[(y + 1) * s.texture.width + x]
                - s.texture.val[(y - 1) * s.texture.width + x]) / 2;
    coef[0] /= 0xFFFFFF;
    coef[1] /= 0xFFFFFF;
    u = ft_sub_vector(obj.p, obj.center);
    ft_normalize_vector(&u);
    v = ft_cross_product(u, obj.normal);
    ft_normalize_vector(&v);
    u = ft_k_vct_prod(coef[0], u);
    v = ft_k_vct_prod(coef[1], v);
    obj.normal = ft_add_vector(obj.normal, ft_add_vector(u,v));
    ft_normalize_vector(&obj.normal);
    return (obj.normal);
}

t_rgb           ft_plane_texture(t_scene s, t_obj_color obj)
{
    //Hacer que funcione para planos en cualquier dirección
    int                 color;
    int                 x;
    int                 y;
    t_rgb               rgb;

    x = ft_abs((int)obj.p.x % s.texture.width);
    y = (s.texture.height - 1) - ft_abs((int)obj.p.y % s.texture.height);
    color = s.texture.val[y * s.texture.width + x];
    rgb.r = (color & 0xFF000000) >> 24;
    rgb.g = (color & 0x00FF0000) >> 16;
    rgb.b = (color & 0x0000FF00) >> 8;
    return (rgb);
}

t_obj_color     ft_disruption(t_scene s, t_obj_color obj)
{
    if (s.option[1])
        obj.normal = ft_wave_normal(obj);
    if (s.option[2])
        obj.rgb = ft_checkered_pattern(obj.p, obj.rgb);
    if (s.option[3])
        obj.rgb = ft_rainbow_pattern(obj.normal, obj.rgb);
    if (s.option[4])
        obj.normal = ft_bumpmap(s, obj);
    if (s.option[5])
        obj.rgb = ft_plane_texture(s, obj);
    return (obj);
}
