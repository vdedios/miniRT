#include "miniRT.h"

//ft_draw_triangle(double *c_ray, t_s s, int *color)
int		ft_draw_triangle(t_scene s, t_ray *r)
{
    s.triangle[0]->n = 0;
    s.triangle[0]->e0 = ft_sub_vector(s.triangle[0]->b, s.triangle[0]->a);
    s.triangle[0]->e1 = ft_sub_vector(s.triangle[0]->c, s.triangle[0]->b);
    s.triangle[0]->e2 = ft_sub_vector(s.triangle[0]->a, s.triangle[0]->c);
    s.triangle[0]->n_aux = ft_cross_product(s.triangle[0]->e0, ft_sub_vector(s.triangle[0]->c, s.triangle[0]->a));
    s.triangle[0]->pl = ft_sub_vector(s.light[0]->pos, s.triangle[0]->a);
    s.triangle[0]->po = ft_sub_vector(s.camera[0]->pos, s.triangle[0]->a);
    if (ft_dot_product(s.triangle[0]->pl, s.triangle[0]->n_aux) < 0)
        s.triangle[0]->n = ft_minus_vector(s.triangle[0]->n_aux);
    s.triangle[0]->den = ft_dot_product(r->global,s.triangle[0]->n_aux);
    s.triangle[0]->i = -1;
    if (ft_dot_product(s.triangle[0]->pl,s.triangle[0]->n_aux) * ft_dot_product(s.triangle[0]->po,s.triangle[0]->n_aux)
            > 0 && ft_dot_product(s.triangle[0]->n_aux, r->global) < 0)
    {
        s.triangle[0]->qo = ft_sub_vector(s.triangle[0]->a, s.camera[0]->pos);
        s.triangle[0]->num = ft_dot_product(s.triangle[0]->qo, s.triangle[0]->n_aux);
        r->t = s.triangle[0]->num / s.triangle[0]->den;
        s.triangle[0]->p = ft_add_vector(s.camera[0]->pos, ft_k_vct_prod(r->t, r->global));
        s.triangle[0]->p0 = ft_sub_vector(s.triangle[0]->p, s.triangle[0]->a);
        s.triangle[0]->p1 = ft_sub_vector(s.triangle[0]->p, s.triangle[0]->b);
        s.triangle[0]->p2 = ft_sub_vector(s.triangle[0]->p, s.triangle[0]->c);
        if (s.triangle[0]->n && (ft_dot_product(s.triangle[0]->n_aux, ft_cross_product(s.triangle[0]->e0, s.triangle[0]->p0)) > 0
                    || ft_dot_product(s.triangle[0]->n_aux, ft_cross_product(s.triangle[0]->e1, s.triangle[0]->p1)) > 0
                    || ft_dot_product(s.triangle[0]->n_aux, ft_cross_product(s.triangle[0]->e2, s.triangle[0]->p2)) > 0))
            return (0);
        else if (!s.triangle[0]->n && (ft_dot_product(s.triangle[0]->n_aux, ft_cross_product(s.triangle[0]->e0, s.triangle[0]->p0)) < 0
                    || ft_dot_product(s.triangle[0]->n_aux, ft_cross_product(s.triangle[0]->e1, s.triangle[0]->p1)) < 0
                    || ft_dot_product(s.triangle[0]->n_aux, ft_cross_product(s.triangle[0]->e2, s.triangle[0]->p2)) < 0))
            return (0);
        s.triangle[0]->l = ft_sub_vector(s.light[0]->pos, s.triangle[0]->p);
        r->color = s.triangle[0]->rgb | ft_shading(s.triangle[0]->n_aux, s.triangle[0]->l);
        return (1);
    }
    return (0);
}
