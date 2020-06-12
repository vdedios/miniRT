#include "miniRT.h"

double          ft_get_p_param(t_scene s,  t_vector p0,  int i)
{
    double p;

    if (s.triangle[i]->equation == 0)
        p = (s.triangle[i]->e1.y * p0.x
                - s.triangle[i]->e1.x * p0.y) / s.triangle[i]->det;
    else if (s.triangle[i]->equation == 1)
        p = (s.triangle[i]->e1.z * p0.y
                - s.triangle[i]->e1.y * p0.z) / s.triangle[i]->det;
    else
        p = (s.triangle[i]->e1.z * p0.x
                - s.triangle[i]->e1.x * p0.z) / s.triangle[i]->det;
    return (p);
}

double          ft_get_q_param(t_scene s,  t_vector p0,  int i)
{
    double q;

    if (s.triangle[i]->equation == 0)
        q = (s.triangle[i]->e0.x * p0.y
                - s.triangle[i]->e0.y * p0.x) / s.triangle[i]->det;
    else if (s.triangle[i]->equation == 1)
        q = (s.triangle[i]->e0.y * p0.z
                - s.triangle[i]->e0.z * p0.y) / s.triangle[i]->det;
    else
        q = (s.triangle[i]->e0.x * p0.z
                - s.triangle[i]->e0.z * p0.x) / s.triangle[i]->det;
    return (q);
}

int		ft_is_inside_triangle(t_scene s,  t_auxplane *auxplane, int i)
{
    double p;
    double q;
    t_vector p0;

    p0 = ft_sub_vector(auxplane->p, s.triangle[i]->a);
    p = ft_get_p_param(s, p0, i);
    q = ft_get_q_param(s, p0, i);
    if ((p >= 0 && p <= 1) && (q >= 0 && q <= 1)
            && ((p + q) >= 0 && (p + q) <= 1))
        return (1);
    return (0);
}

int             ft_intersect_triangle(t_scene *s, t_ray *r, int i)
{
    double last_t;
    t_auxplane auxplane;

    auxplane.point = s->triangle[i]->a;
    auxplane.n = ft_cross_product(s->triangle[i]->e1, s->triangle[i]->e0);
    last_t = r->t;
    if (ft_intersect_plane(s, &auxplane, r))
        if (ft_get_point_plane(s, &auxplane, r))
            if (ft_is_inside_triangle(*s, &auxplane, i))
            {
                s->triangle[i]->p = auxplane.p;
                if (auxplane.den > 0)
                    s->triangle[i]->n_aux = ft_k_vct_prod(-1, auxplane.n);
                else
                    s->triangle[i]->n_aux = auxplane.n;
                return (1);
            }
    r->t = last_t;
    return (0);
}

int		ft_draw_triangle(t_scene s, t_ray *r, int i)
{
    if (ft_intersect_triangle(&s, r, i))
    {
        s.triangle[i]->l = ft_sub_vector(s.light[0]->pos, s.triangle[i]->p);
        r->color = ft_mix_color(
                ft_shading(s, s.triangle[i]->p, s.triangle[i]->n_aux, s.triangle[i]->l)
                , s.triangle[i]->rgb);
        return (1);
    }
    return (0);
}
