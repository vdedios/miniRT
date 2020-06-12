#include "miniRT.h"

int		ft_shadow_triangle(t_scene s, t_ray *r, int i)
{
    if (ft_intersect_triangle(&s, r, i))
        if (ft_between_light_source(s.light[0]->pos, s.triangle[i]->p, r->origin))
            return (1);
    return (0);
}
