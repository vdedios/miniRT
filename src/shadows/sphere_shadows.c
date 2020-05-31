#include "miniRT.h"

int             ft_shadow_sphere(t_scene s, t_ray *r, int i)
{
    if (ft_intersect_sphere(&s, r, i))
    {
        r->t = s.sphere[i]->p_oc - sqrt(pow(s.sphere[i]->diameter / 2, 2.0) - pow(s.sphere[i]->d, 2.0));
        s.sphere[i]->p = ft_add_vector(r->origin, ft_k_vct_prod(r->t, r->global));
        if (ft_between_light_source(s.light[0]->pos, s.sphere[i]->p, r->origin))
            return (1);
    }
    return (0);
}
