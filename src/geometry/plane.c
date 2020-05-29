#include "miniRT.h"

int		ft_intersect_plane(t_scene *s, t_auxplane *plane, t_ray *r)
{
    plane->n_aux = ft_k_vct_prod(1, plane->n);
    plane->p_l = ft_sub_vector(s->light[0]->pos, plane->point);
    plane->po = ft_sub_vector(s->camera[0]->pos, plane->point);
    if (ft_dot_product(plane->p_l, plane->n_aux) < 0)
        ft_minus_vector(plane->n_aux);	
    plane->den = ft_dot_product(r->global, plane->n_aux);
    if (ft_dot_product(plane->p_l,plane->n_aux)
            * ft_dot_product(plane->po,plane->n_aux)
            > 0 && ft_dot_product(plane->n_aux, r->global) < 0)
        return (1);
    return (0);
}

int             ft_get_point_plane(t_scene *s, t_auxplane *plane, t_ray *r)
{
    double t;

    plane->qo = ft_sub_vector(plane->point, s->camera[0]->pos);
    plane->num = ft_dot_product(plane->qo, plane->n_aux);
    t = plane->num / plane->den;
    if (t > r->t)
        return (0);
    r->t = t;
    plane->p= ft_add_vector(s->camera[0]->pos,
            ft_k_vct_prod(r->t, r->global));
    return (1);
}

int		ft_draw_plane(t_scene s, t_ray *r, int i)
{
    t_auxplane auxplane;

    auxplane.point = s.plane[i]->point;
    auxplane.n = s.plane[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
        {
            auxplane.l= ft_sub_vector(s.light[0]->pos, auxplane.p);
            r->color = s.plane[i]->rgb | ft_shading(auxplane.n_aux, auxplane.l);
            return (1);
        }
    return (0);
}
