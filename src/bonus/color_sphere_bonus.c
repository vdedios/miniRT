#include "miniRT.h"

t_rgb           ft_sphere_texture(t_obj_color obj)
{
    double              u[2];
    double              angle[2];
    double              alpha;
    t_vector            cp;
    t_vector            equator;

    equator = (t_vector){-5, -1, 0};
    ft_normalize_vector(&equator);
    cp = ft_sub_vector(obj.p, obj.center);
    ft_normalize_vector(&cp);
    angle[0] = acos( -1 * ft_dot_product((t_vector){0, 0, -1}, cp));
    u[1] = angle[0] / M_PI;
    alpha = -1 * ft_dot_product(cp, equator) / sin(angle[0]);
    alpha += alpha > 0 ? -1 * FLT_EPSILON : FLT_EPSILON;
    angle[1] = acos(alpha) / (2 * M_PI);
    if (ft_dot_product( ft_cross_product((t_vector){0, 0, -1},equator), cp) > 0)
        u[0] = angle[1];
    else
        u[0] = 1 - angle[1];
    return (ft_color_texture(obj, (int)(u[0] * obj.bonus.texture.width),
                (int)(u[1] * obj.bonus.texture.height)));
}

t_rgb           ft_rainbow_pattern(t_vector n, t_rgb color)
{
    color.r = 255 * ft_abs(n.x);
    color.g = 255 * ft_abs(n.y);
    color.b = 255 * ft_abs(n.z);
    ft_check_rgb_range(&color);
    return (color);
}
