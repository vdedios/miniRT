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

t_rgb           ft_mix_color(t_rgb amb, t_rgb spot)
{
    t_rgb color;

    color.r = amb.r + spot.r;
    color.g = amb.g + spot.g;
    color.b = amb.b + spot.b;
    ft_check_rgb_range(&color);
    return(color);
}

t_rgb           ft_ambient(t_scene s, t_obj_color obj)
{
    t_rgb       color;

    color.r = s.ambient.intensity * s.ambient.rgb.r * obj.rgb.r / 255;
    color.g = s.ambient.intensity * s.ambient.rgb.g * obj.rgb.g / 255;
    color.b = s.ambient.intensity * s.ambient.rgb.b * obj.rgb.b / 255;
    return (color);
}

t_rgb		ft_spot_light(t_scene s, t_obj_color obj)
{
    t_rgb       color;
    double      specular;
    double	diffuse;
    double      kd;
    t_vector    wave_n;

    //diffuse = ft_dot_product(obj.light, obj.normal);
    wave_n = ft_wave_normal(obj);
    diffuse = ft_dot_product(obj.light, wave_n);
    if (diffuse < 0)
        kd = 0;
    else
        kd = s.light[0]->intensity;
    specular = pow(fmax(diffuse, 0.0), 30);
    color.r = kd * s.light[0]->rgb.r * (obj.rgb.r * diffuse / 255 + specular);
    color.g = kd * s.light[0]->rgb.g * (obj.rgb.g * diffuse / 255 + specular);
    color.b = kd * s.light[0]->rgb.b * (obj.rgb.b * diffuse / 255 + specular);
    return (color);
}

int             ft_get_color(t_scene s, t_obj_color obj)
{
    t_rgb       color;
    t_rgb       aux_color;
    t_ray       shadow;
    int         i;

    i = 0;
    color = (t_rgb){0, 0, 0};
    while (s.light[i])
    {
        obj.light = ft_sub_vector(s.light[i]->pos, obj.p);
        ft_normalize_vector(&obj.light);
        ft_normalize_vector(&obj.normal);
        shadow.global = obj.light;
        shadow.origin = obj.p;
        aux_color = ft_ambient(s, obj);
        if (!ft_shadows(s, &shadow))
            aux_color = ft_mix_color(aux_color, ft_spot_light(s, obj));
        color = ft_mix_color(color, aux_color);
        i++;
    }
    return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}
