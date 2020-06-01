#include "miniRT.h"

int             ft_intersect_sphere(t_scene *s, t_ray *r, int i)
{
    if (r->origin)
        s->sphere[i]->oc = ft_sub_vector(s->sphere[i]->center, r->origin);
    else
        s->sphere[i]->oc = ft_sub_vector(s->sphere[i]->center, s->camera[0]->pos);
    s->sphere[i]->p_oc = ft_dot_product(s->sphere[i]->oc, r->global);
    if (s->sphere[i]->p_oc < 0)
        return (0);
    s->sphere[i]->d = sqrt(pow(ft_mod_vector(s->sphere[i]->oc), 2.0) - pow(s->sphere[i]->p_oc, 2.0));
    if (s->sphere[i]->d > (s->sphere[i]->diameter / 2))
        return (0);
    return (1);
}

int		ft_draw_sphere(t_scene s, t_ray *r, int i)
{
    double t;

    if (!ft_intersect_sphere(&s, r, i))
        return (0);
    t = s.sphere[i]->p_oc - sqrt(pow(s.sphere[i]->diameter / 2, 2.0) - pow(s.sphere[i]->d, 2.0));
    if (t > r->t)
        return (0);
    r->t = t;
    s.sphere[i]->p = ft_add_vector(s.camera[0]->pos, ft_k_vct_prod(r->t, r->global));
    s.sphere[i]->n = ft_sub_vector(s.sphere[i]->p, s.sphere[i]->center);
    s.sphere[i]->l = ft_sub_vector(s.light[0]->pos, s.sphere[i]->p);
    r->color = s.sphere[i]->rgb | ft_shading(s, s.sphere[i]->p, s.sphere[i]->n, s.sphere[i]->l);
    return (1);
}
