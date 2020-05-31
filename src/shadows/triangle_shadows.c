#include "miniRT.h"

int		ft_shadow_triangle(t_scene s, t_ray *r, int i)
{
    if (ft_boundaries_triangle(s, r, i))
    {
        s.triangle[i]->qo = ft_sub_vector(s.triangle[i]->a, r->origin);
        s.triangle[i]->num = ft_dot_product(s.triangle[i]->qo, s.triangle[i]->n_aux);
        r->t = s.triangle[i]->num / s.triangle[i]->den;
        if (ft_get_point_triangle(s, r, i))
            if (ft_between_light_source(s.light[0]->pos, s.triangle[i]->p, r->origin))
            return (1);
    }
    return (0);
}
