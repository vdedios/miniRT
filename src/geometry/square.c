#include "miniRT.h"

int		ft_intersect_inside_square(t_scene s,  t_auxplane *auxplane, int i)
{
    s.square[i]->dx = ft_set_axis('x');
    s.square[i]->dy = ft_cross_product(auxplane->n,
            s.square[i]->dx);
    if (!ft_isvoid(s.square[i]->dy))
    {
        s.square[i]->dx = ft_set_axis('y');
        s.square[i]->dy = ft_cross_product(auxplane->n,
            s.square[i]->dx);
    }
    ft_normalize_vector(&s.square[i]->dx);
    ft_normalize_vector(&s.square[i]->dy);
    if (ft_abs(ft_dot_product(s.square[i]->dx,
        ft_sub_vector(auxplane->p, s.square[i]->center)))
            > s.square[i]->side || ft_abs(ft_dot_product(s.square[i]->dy,
            ft_sub_vector(auxplane->p, s.square[i]->center)))
            > s.square[i]->side)
        return (0);
    return (1);
}

int		ft_draw_square(t_scene s, t_ray *r, int i)
{
    double      last_t;
    t_auxplane  auxplane;
    t_obj_color obj;

    last_t = r->t;
    auxplane.point = s.square[i]->center;
    auxplane.n = s.square[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
            if (ft_intersect_inside_square(s, &auxplane, i))
            {
                if (auxplane.den > 0)
                    auxplane.n = ft_k_vct_prod(-1, auxplane.n);
                obj.p = auxplane.p;
                obj.normal = auxplane.n;
                obj.rgb = s.square[i]->rgb;
                obj.bonus = s.square[i]->bonus; 
                r->color = ft_get_color(s, obj);
                return (1);
            }
    r->t = last_t;
    return (0);
}
