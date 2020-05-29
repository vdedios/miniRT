#include "miniRT.h"

int		ft_draw_plane(t_scene s, t_ray *r)
{
    s.plane[0]->n_aux = ft_k_vct_prod(1, s.plane[0]->n);
    s.plane[0]->p_l = ft_sub_vector(s.light[0]->pos, s.plane[0]->point);
    s.plane[0]->po = ft_sub_vector(s.camera[0]->pos, s.plane[0]->point);
    if (ft_dot_product(s.plane[0]->p_l, s.plane[0]->n_aux) < 0)
        ft_minus_vector(s.plane[0]->n_aux);	
    s.plane[0]->den = ft_dot_product(r->global, s.plane[0]->n_aux);
    if (ft_dot_product(s.plane[0]->p_l,s.plane[0]->n_aux) * ft_dot_product(s.plane[0]->po,s.plane[0]->n_aux)
            > 0 && ft_dot_product(s.plane[0]->n_aux, r->global) < 0)
    {
        s.plane[0]->qo = ft_sub_vector(s.plane[0]->point, s.camera[0]->pos);
        s.plane[0]->num = ft_dot_product(s.plane[0]->qo, s.plane[0]->n_aux);
        r->t = s.plane[0]->num / s.plane[0]->den;
        //Comparamos la t local calculada con la del rayo, si es mayor guardamos
        //A partir de aquí es calcular el color
        s.plane[0]->p= ft_add_vector(s.camera[0]->pos, ft_k_vct_prod(r->t, r->global));
        s.plane[0]->l= ft_sub_vector(s.light[0]->pos, s.plane[0]->p);
        r->color = s.plane[0]->rgb | ft_shading(s.plane[0]->n_aux, s.plane[0]->l);
        return (1);
    }
    return (0);
}
