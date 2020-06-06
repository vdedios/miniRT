#include "miniRT.h"

void            ft_calc_surface_cylinder(t_scene *s, t_ray *r, int i)
{
    if (r->origin)
        s->cylinder[i]->oc = ft_sub_vector(r->origin,
                s->cylinder[i]->point);
    else
        s->cylinder[i]->oc = ft_sub_vector(s->camera[s->i_cam]->pos,
                s->cylinder[i]->point);
    s->cylinder[i]->a = 1 - pow(ft_dot_product(r->global,
                s->cylinder[i]->n), 2.0);
    s->cylinder[i]->b = 2 * (ft_dot_product(r->global, s->cylinder[i]->oc)
            - ft_dot_product(r->global, s->cylinder[i]->n)
            * ft_dot_product(s->cylinder[i]->oc, s->cylinder[i]->n));
    s->cylinder[i]->c = ft_dot_product(s->cylinder[i]->oc, s->cylinder[i]->oc)
        - pow(ft_dot_product(s->cylinder[i]->oc, s->cylinder[i]->n), 2.0)
        - pow((s->cylinder[i]->diameter / 2), 2.0);
    s->cylinder[i]->discr = s->cylinder[i]->b * s->cylinder[i]->b - 4
        * s->cylinder[i]->a * s->cylinder[i]->c;
}

int		ft_intersect_cylinder(t_scene *s, t_ray *r, int i)
{
    double t;

    t = 0;
    ft_calc_surface_cylinder(s, r, i);
    if (s->cylinder[i]->discr < 0)
        return (0);
    s->cylinder[i]->x1 = (- s->cylinder[i]->b
            + sqrt(s->cylinder[i]->discr)) / (2 * s->cylinder[i]->a);
    s->cylinder[i]->x2 = (- s->cylinder[i]->b
            - sqrt(s->cylinder[i]->discr)) / (2 * s->cylinder[i]->a);
    if (s->cylinder[i]->x1 > s->cylinder[i]->x2)
        t = s->cylinder[i]->x2;
    /*
       if (t < 0)
       t = s->cylinder[i]->x1;
       */
    if (t < 0)
        return (0);
    if (t > r->t && !r->origin)
        return (0);
    r->t = t;
    return (1);
}

int             ft_draw_caps(t_scene s, t_ray *r, int i)
{
    t_auxplane auxplane;

    if (s.cylinder[i]->m && s.cylinder[i]->m > s.cylinder[i]->height)
        auxplane.point = ft_add_vector(s.cylinder[i]->point,
                ft_k_vct_prod(s.cylinder[i]->height, s.cylinder[i]->n));
    //ojo con esto siempre asigna desde abajo y hace la sombra desde abajo
    else
        auxplane.point = s.cylinder[i]->point;
    auxplane.n = s.cylinder[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
            if (ft_mod_vector(ft_sub_vector(auxplane.p, auxplane.point))
                    < (s.cylinder[i]->diameter / 2))
            {
                if (!r->origin)
                {
                    auxplane.l= ft_sub_vector(s.light[0]->pos, auxplane.p);
                    r->color = s.cylinder[i]->rgb
                        & ft_shading(s,  auxplane.p, auxplane.n_aux, auxplane.l);
                }
                return (1);
            }
    return (0);
}

int		ft_draw_cylinder(t_scene s, t_ray *r, int i)
{
    double t;

    t = r->t;
    if (ft_intersect_cylinder(&s, r, i))
    {
        s.cylinder[i]->p = ft_add_vector(s.camera[s.i_cam]->pos,
                ft_k_vct_prod(r->t, r->global));
        s.cylinder[i]->m = ft_dot_product(s.cylinder[i]->n,
                ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->point));
        s.cylinder[i]->center = ft_add_vector(s.cylinder[i]->point,
                ft_k_vct_prod(s.cylinder[i]->m, s.cylinder[i]->n));
        s.cylinder[i]->nsurface= ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->center);
        s.cylinder[i]->l = ft_sub_vector(s.light[0]->pos, s.cylinder[i]->p);
        if (s.cylinder[i]->m < s.cylinder[i]->height && s.cylinder[i]->m > 0)
        {
            r->color = s.cylinder[i]->rgb
                & ft_shading(s, s.cylinder[i]->p, s.cylinder[i]->nsurface, s.cylinder[i]->l);
            return (1);
        }
        r->t = t;
    }
    return (ft_draw_caps(s, r, i));
}
