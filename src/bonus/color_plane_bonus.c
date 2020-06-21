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

t_vector        ft_bumpmap(t_obj_color obj)
{
    double      coef[2];
    int         x;
    int         y;
    t_vector    u;
    t_vector    v;

    x = ft_abs((int)obj.p.x % obj.bonus.texture.width);
    y = (obj.bonus.texture.height - 1) - ft_abs((int)obj.p.y % obj.bonus.texture.height);
    if ((x - 1) >= 0 && (x + 1) < obj.bonus.texture.width)
        coef[0] = (obj.bonus.texture.val[y * obj.bonus.texture.width + (x + 1)]
                - obj.bonus.texture.val[y * obj.bonus.texture.width + (x - 1)]) / 2;
    if ((y - 1) >= 0 && (y + 1) < obj.bonus.texture.height)
        coef[1] = (obj.bonus.texture.val[(y + 1) * obj.bonus.texture.width + x]
                - obj.bonus.texture.val[(y - 1) * obj.bonus.texture.width + x]) / 2;
    coef[0] /= 0xFFFFFF;
    coef[1] /= 0xFFFFFF;
    u = (t_vector){coef[1], 0, 0};
    v = (t_vector){0, coef[0], 0};
    obj.normal = ft_add_vector(obj.normal, ft_add_vector(u,v));
    ft_normalize_vector(&obj.normal);
    return (obj.normal);
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
