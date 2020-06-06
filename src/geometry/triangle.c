#include "miniRT.h"

int            ft_boundaries_triangle(t_scene s, t_ray *r, int i)
{
    s.triangle[i]->n = 0;
    s.triangle[i]->e0 = ft_sub_vector(s.triangle[i]->b, s.triangle[i]->a);
    s.triangle[i]->e1 = ft_sub_vector(s.triangle[i]->c, s.triangle[i]->b);
    s.triangle[i]->e2 = ft_sub_vector(s.triangle[i]->a, s.triangle[i]->c);
    s.triangle[i]->n_aux = ft_cross_product(s.triangle[i]->e0,
            ft_sub_vector(s.triangle[i]->c, s.triangle[i]->a));
    s.triangle[i]->pl = ft_sub_vector(s.light[0]->pos, s.triangle[i]->a);
    if (r->origin)
        s.triangle[i]->po = ft_sub_vector(r->origin, s.triangle[i]->a);
    else
        s.triangle[i]->po = ft_sub_vector(s.camera[s.i_cam]->pos, s.triangle[i]->a);
    if (ft_dot_product(s.triangle[i]->pl, s.triangle[i]->n_aux) < 0)
        s.triangle[i]->n = ft_minus_vector(s.triangle[i]->n_aux);
    s.triangle[i]->den = ft_dot_product(r->global, s.triangle[i]->n_aux);
    if (r->origin)
        return (1);
    if (ft_dot_product(s.triangle[i]->pl, s.triangle[i]->n_aux)
            * ft_dot_product(s.triangle[i]->po,s.triangle[i]->n_aux)
            > 0 && ft_dot_product(s.triangle[i]->n_aux, r->global) < 0)
        return (1);
    return (0);
}

int             ft_get_point_triangle(t_scene s, t_ray *r, int i)
{
    if (r->origin)
        s.triangle[i]->p = ft_add_vector(r->origin,
                ft_k_vct_prod(r->t, r->global));
    else
        s.triangle[i]->p = ft_add_vector(s.camera[s.i_cam]->pos,
                ft_k_vct_prod(r->t, r->global));
    s.triangle[i]->p0 = ft_sub_vector(s.triangle[i]->p, s.triangle[i]->a);
    s.triangle[i]->p1 = ft_sub_vector(s.triangle[i]->p, s.triangle[i]->b);
    s.triangle[i]->p2 = ft_sub_vector(s.triangle[i]->p, s.triangle[i]->c);
    if (s.triangle[i]->n && (ft_dot_product(s.triangle[i]->n_aux,
                    ft_cross_product(s.triangle[i]->e0, s.triangle[i]->p0)) > 0
                || ft_dot_product(s.triangle[i]->n_aux,
                    ft_cross_product(s.triangle[i]->e1, s.triangle[i]->p1)) > 0
                || ft_dot_product(s.triangle[i]->n_aux,
                    ft_cross_product(s.triangle[i]->e2, s.triangle[i]->p2)) > 0))
        return (0);
    else if (!s.triangle[i]->n && (ft_dot_product(s.triangle[i]->n_aux,
                    ft_cross_product(s.triangle[i]->e0, s.triangle[i]->p0)) < 0
                || ft_dot_product(s.triangle[i]->n_aux,
                    ft_cross_product(s.triangle[i]->e1, s.triangle[i]->p1)) < 0
                || ft_dot_product(s.triangle[i]->n_aux,
                    ft_cross_product(s.triangle[i]->e2, s.triangle[i]->p2)) < 0))
        return (0);
    return (1);
}

int		ft_draw_triangle(t_scene s, t_ray *r, int i)
{
    double      t;
    int         r_c;
    int         g_c;
    int         b_c;

    if (ft_boundaries_triangle(s, r, i))
    {
        s.triangle[i]->qo = ft_sub_vector(s.triangle[i]->a, s.camera[s.i_cam]->pos);
        s.triangle[i]->num = ft_dot_product(s.triangle[i]->qo, s.triangle[i]->n_aux);
        t = r->t;
        r->t = s.triangle[i]->num / s.triangle[i]->den;
        if (r->t > t || !ft_get_point_triangle(s, r, i))
        {
            r->t = t;
            return (0);
        }
        s.triangle[i]->l = ft_sub_vector(s.light[0]->pos, s.triangle[i]->p);
        r->color = ft_shading(s, s.triangle[i]->p, s.triangle[i]->n_aux, s.triangle[i]->l);
        //cambiar modelo sustractivo
        r_c = (((r->color & 0x00FF0000) >> 16) * ((s.triangle[i]->rgb & 0x00FF0000) >> 16)) / 255;
        g_c = (((r->color & 0x0000FF00) >> 8) * ((s.triangle[i]->rgb & 0x0000FF00) >> 8)) / 255;
        b_c = (((r->color & 0x000000FF)) * (s.triangle[i]->rgb & 0x000000FF)) / 255;
        r->color = ((r_c << 16) + (g_c << 8) + b_c);
        return (1);
    }
    return (0);
}
