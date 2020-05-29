#include "miniRT.h"

// Quedaría subdividir la función. De momento así hasta que quede claro cómo va a ser el pipeline
int		ft_draw_square(t_scene s, t_ray *r)
{
    s.square[0]->n_aux = ft_k_vct_prod(1, s.square[0]->n);
    s.square[0]->pl = ft_sub_vector(s.light[0]->pos, s.square[0]->center);
    s.square[0]->po = ft_sub_vector(s.camera[0]->pos, s.square[0]->center);
    if (ft_dot_product(s.square[0]->pl, s.square[0]->n_aux) < 0)
        ft_minus_vector(s.square[0]->n_aux);	
    s.square[0]->den = ft_dot_product(r->global, s.square[0]->n_aux);
    s.square[0]->i = -1;
    if (ft_dot_product(s.square[0]->pl,s.square[0]->n_aux)
            * ft_dot_product(s.square[0]->po,s.square[0]->n_aux)
            > 0 && ft_dot_product(s.square[0]->n_aux, r->global) < 0)
    {
        s.square[0]->qo = ft_sub_vector(s.square[0]->center, s.camera[0]->pos);
        s.square[0]->num = ft_dot_product(s.square[0]->qo, s.square[0]->n_aux);
        r->t = s.square[0]->num / s.square[0]->den;
        s.square[0]->p = ft_add_vector(s.camera[0]->pos,
                ft_k_vct_prod(r->t, r->global));
        if (!s.square[0]->dx)
        {
            //arreglar on perspectiva hacia arriba
            s.square[0]->dx = ft_cross_product(s.square[0]->n_aux,
                    s.camera[0]->n);
            if (!ft_mod_vector(s.square[0]->dx))
                s.square[0]->dx = ft_set_axis('x');
            s.square[0]->dy = ft_cross_product(s.square[0]->n_aux,
                    s.square[0]->dx);
            ft_normalise_vector(s.square[0]->dx);
            ft_normalise_vector(s.square[0]->dy);
        }
        if (ft_abs(ft_dot_product(s.square[0]->dx,
                ft_sub_vector(s.square[0]->p, s.square[0]->center))) >
                    s.square[0]->side || ft_abs(ft_dot_product(s.square[0]->dy,
                ft_sub_vector(s.square[0]->p, s.square[0]->center))) >
                    s.square[0]->side)
            return (0);
        s.square[0]->l = ft_sub_vector(s.light[0]->pos, s.square[0]->p);
        r->color = s.square[0]->rgb | ft_shading(s.square[0]->n_aux,
                s.square[0]->l);
        return (1);
    }
    return (0);
}
