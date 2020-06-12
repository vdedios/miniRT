#include "miniRT.h"

int             ft_shadow_cylinder(t_scene s, t_ray *r, int i)
{       
    s.cylinder[i]->m = 0;
    if (ft_intersect_cylinder(&s, r, i))
    {
        s.cylinder[i]->p = ft_add_vector(r->origin,
                ft_k_vct_prod(r->t, r->global));
        if (ft_between_light_source(s.light[0]->pos, s.cylinder[i]->p, r->origin))
        {
            s.cylinder[i]->m = ft_dot_product(s.cylinder[i]->n,
                    ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->point));
            s.cylinder[i]->center = ft_add_vector(s.cylinder[i]->point,
                    ft_k_vct_prod(s.cylinder[i]->m, s.cylinder[i]->n));
            s.cylinder[i]->nsurface= ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->center);
            s.cylinder[i]->l = ft_sub_vector(s.light[0]->pos, s.cylinder[i]->p);
            if (s.cylinder[i]->m < s.cylinder[i]->height && s.cylinder[i]->m > 0)
                return (1);
        }
    }
    if (ft_intersect_caps(&s, r, i))
        if (ft_between_light_source(s.light[0]->pos, s.cylinder[i]->p, r->origin))
            return (1);
    return (0);
}
