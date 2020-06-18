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
    u = (t_vector){coef[1], 0, 0};
    v = (t_vector){0, coef[0], 0};
    obj.normal = ft_add_vector(obj.normal, ft_add_vector(u,v));
    ft_normalize_vector(&obj.normal);
    return (obj.normal);
}

t_rgb           ft_color_texture(t_scene s, int x, int y)
{
    int                 color;
    t_rgb               rgb;

    color = s.texture.val[y * s.texture.width + x];
    rgb.r = (color & 0x00FF0000) >> 16;
    rgb.g = (color & 0x0000FF00) >> 8;
    rgb.b = (color & 0x000000FF);
    return (rgb);
}

t_rgb           ft_plane_texture(t_scene s, t_obj_color obj)
{
    int                 x;
    int                 y;

    if (ft_abs(ft_dot_product(obj.normal, (t_vector){1, 0, 0})) == 1)
        x = ft_abs((int)obj.p.z % s.texture.width);
    else
        x = ft_abs((int)obj.p.x % s.texture.width);
    if (ft_abs(ft_dot_product(obj.normal, (t_vector){0, 1, 0})) == 1)
        y = (s.texture.height - 1) - ft_abs((int)obj.p.z % s.texture.height);
    else
        y = (s.texture.height - 1) - ft_abs((int)obj.p.y % s.texture.height);
    return (ft_color_texture(s, x, y));
}

t_rgb           ft_sphere_texture(t_scene s, t_obj_color obj)
{
    double              u;
    double              v;
    double              angle[2];
    t_vector            cp;
    t_vector            equator;

    equator = (t_vector){0, 1, 0};
    ft_normalize_vector(&equator);
    cp = ft_sub_vector(obj.p, obj.center);
    ft_normalize_vector(&cp);
    angle[0] = acos( -1 * ft_dot_product((t_vector){0, 0, -1}, cp));
    v = angle[0] / M_PI;
    angle[1] = acos(-1 * ft_dot_product(cp, equator)
            / sin(angle[0])) / (2 * M_PI);
    if (ft_dot_product( ft_cross_product((t_vector){0, 0, -1},equator), cp) > 0)
        u = angle[1];
    else
        u = 1 - angle[1];
    return (ft_color_texture(s, (int)(u * s.texture.width), (int)(v * s.texture.height)));
}

t_vector        ft_parallel_light(t_scene s, t_obj_color obj)
{
    t_vector    light_dir;
    (void)s;

    light_dir = obj.light_pos;
    ft_normalize_vector(&light_dir);
    return (light_dir);
}

t_rgb           ft_sepia_filter(t_scene s, t_rgb in_color)
{
    t_rgb       out_color;

    if (s.option[8])
    {
        out_color.r = (in_color.r * 0.393) + (in_color.g * 0.769) + (in_color.b * 0.189);
        out_color.g = (in_color.r * 0.349) + (in_color.g * 0.686) + (in_color.b * 0.168);
        out_color.b = (in_color.r * 0.272) + (in_color.g * 0.534) + (in_color.b * 0.131);
        ft_check_rgb_range(&out_color);
        return (out_color);
    }
    return (in_color);
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
    if (s.option[6])
        obj.rgb = ft_sphere_texture(s, obj);
    if (s.option[7])
        obj.light = ft_parallel_light(s, obj);
    return (obj);
}

//---------------------
void            ft_render_pxl(double px, double py, t_ray *ray, t_scene *s);
//---------------------

void            ft_render_pxl_antialiasing(double px, double py, t_ray *ray, t_scene *s)
{
    int         i;
    int         j;
    t_rgb       color;

    color = (t_rgb){0, 0, 0};
    i = 0;
    while(i < 2)
    {
        j = 0;
        while(j < 2)
        {
            ft_render_pxl(px + (i + 0.5) / 2, py + (j + 0.5) / 2, ray, s);
            color.r += (ray->color & 0x00ff0000 ) >> 16;
            color.g += (ray->color & 0x0000ff00 ) >> 8;
            color.b += (ray->color & 0x000000ff );
            j++;
        }
        i++;
    }
    ray->color = ((int)(color.r / 4) << 16) + ((int)(color.g / 4) << 8) + (int)(color.b / 4);
}
