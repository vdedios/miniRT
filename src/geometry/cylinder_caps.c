#include "miniRT.h"

int             ft_intersect_caps(t_scene *s, t_ray *r, int i, t_auxplane *auxplane)
{
    if (ft_intersect_plane(s, auxplane, r))
        if (ft_get_point_plane(s, auxplane, r))
            if (ft_mod_vector(ft_sub_vector(auxplane->p, auxplane->point))
                    < s->cylinder[i]->radius)
            {
                if (auxplane->den > 0)
                    auxplane->n = ft_k_vct_prod(-1, auxplane->n);
                return (1);
            }
    return (0);
}

int             ft_draw_caps(t_scene s, t_ray *r, int i)
{
    double      last_t;
    t_obj_color obj;
    t_auxplane auxplane;

    last_t = r->t;
    if (s.cylinder[i]->m && s.cylinder[i]->m > s.cylinder[i]->height)
        auxplane.point = ft_add_vector(s.cylinder[i]->point,
                ft_k_vct_prod(s.cylinder[i]->height, s.cylinder[i]->n));
    else
        auxplane.point = s.cylinder[i]->point;
    auxplane.n = s.cylinder[i]->n;
    if (ft_intersect_caps(&s, r, i, &auxplane))
    {
        obj.p = auxplane.p;
        obj.normal = auxplane.n;
        obj.rgb = s.cylinder[i]->rgb;
        r->color = ft_get_color(s, obj);
        return (1);
    }
    r->t = last_t;
    return (0);
}
