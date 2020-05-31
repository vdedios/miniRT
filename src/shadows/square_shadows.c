#include "miniRT.h"

int             ft_shadow_square(t_scene s, t_ray *r, int i)
{
    t_auxplane  auxplane;

    auxplane.point = s.square[i]->center;
    auxplane.n = s.square[i]->n;
    if (ft_intersect_shadow_plane(&auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
            if (ft_intersect_inside_square(s, &auxplane, i))
                if (ft_between_light_source(auxplane.p, r->origin, r->global))
                    return (1);
    return (0);
}
