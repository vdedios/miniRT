#include "miniRT.h"

t_vector        ft_get_bumpmap_normal(t_obj_color obj, int x, int y)
{
    double      coef[2];
    t_vector    u;
    t_vector    v;

    if ((x - 1) >= 0 && (x + 1) < obj.bonus.bumpmap.width)
        coef[0] = (obj.bonus.bumpmap.val[y * obj.bonus.bumpmap.width + (x + 1)]
                - obj.bonus.bumpmap.val[y * obj.bonus.bumpmap.width + (x - 1)]) / 2;
    if ((y - 1) >= 0 && (y + 1) < obj.bonus.bumpmap.height)
        coef[1] = (obj.bonus.bumpmap.val[(y + 1) * obj.bonus.bumpmap.width + x]
                - obj.bonus.bumpmap.val[(y - 1) * obj.bonus.bumpmap.width + x]) / 2;
    coef[0] /= 0xFFFFFF;
    coef[1] /= 0xFFFFFF;
    u = (t_vector){coef[1], 0, 0};
    v = (t_vector){0, coef[0], 0};
    obj.normal = ft_add_vector(obj.normal, ft_add_vector(u,v));
    ft_normalize_vector(&obj.normal);
    return (obj.normal);
}

t_vector        ft_bumpmap(t_obj_color obj)
{
    double      x;
    double      y;

    if (obj.bonus.type == 's')
    {
        ft_sphere_coords(obj, &x, &y);
        x *= obj.bonus.bumpmap.width;
        y *= obj.bonus.bumpmap.height;
    }
    else
    {
        x = ft_abs((int)obj.p.x % obj.bonus.bumpmap.width);
        y = (obj.bonus.bumpmap.height - 1)
            - ft_abs((int)obj.p.y % obj.bonus.bumpmap.height);
    }
    return (ft_get_bumpmap_normal(obj, (int)x, (int)y));
}
