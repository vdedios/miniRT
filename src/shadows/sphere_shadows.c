#include "miniRT.h"

int             ft_shadow_sphere(t_scene s, t_ray *r, int i)
{
    if (ft_intersect_sphere(&s, r, i))
        return (1);
    return (0);
}
