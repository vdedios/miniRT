#include "miniRT.h"

int		ft_shadow_triangle(t_scene s, t_ray *r, int i)
{
    t_auxplane  auxplane;

    auxplane.point = s.triangle[i]->a;
    auxplane.n = ft_cross_product(s.triangle[i]->e1, s.triangle[i]->e0);
    if (ft_intersect_triangle(&s, r, i, &auxplane))
        if (ft_between_light_source(s.light[s.i_light]->pos, auxplane.p, r->origin))
            return (1);
    return (0);
}
