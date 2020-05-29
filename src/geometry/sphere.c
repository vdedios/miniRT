#include "miniRT.h"

int		ft_draw_sphere(t_scene s, t_ray *r)
{
    s.sphere[0]->oc = ft_sub_vector(s.sphere[0]->center, s.camera[0]->pos);
    s.sphere[0]->p_oc = ft_dot_product(s.sphere[0]->oc, r->global);
    s.sphere[0]->d = sqrt(pow(ft_mod_vector(s.sphere[0]->oc), 2.0) - pow(s.sphere[0]->p_oc, 2.0));
    if (s.sphere[0]->d > (s.sphere[0]->diameter / 2))
        return (0);
    r->t = s.sphere[0]->p_oc - sqrt(pow(s.sphere[0]->diameter / 2, 2.0) - pow(s.sphere[0]->d, 2.0));
    //Comparamos la t local calculada con la del rayo, si es mayor la guardamos, calculamos
    //color y lo almacenamos
    //A partir de aquí es calcular el color
    s.sphere[0]->p = ft_add_vector(s.camera[0]->pos, ft_k_vct_prod(r->t, r->global));
    s.sphere[0]->n = ft_sub_vector(s.sphere[0]->p, s.sphere[0]->center);
    s.sphere[0]->l = ft_sub_vector(s.light[0]->pos, s.sphere[0]->p);
    r->color = s.sphere[0]->rgb | ft_shading(s.sphere[0]->n, s.sphere[0]->l);
    return (1);
}
