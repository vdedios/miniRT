#include "miniRT.h"

int             ft_shadow_plane(t_scene s, t_ray *r, int i)
{
    t_auxplane auxplane;

    auxplane.point = s.plane[i]->point;
    auxplane.n = s.plane[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
            if (ft_between_light_source(s.light[0]->pos, auxplane.p, r->origin))
                return (1);
    return (0);
}
