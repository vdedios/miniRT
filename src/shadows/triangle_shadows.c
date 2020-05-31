#include "miniRT.h"

int		ft_shadow_triangle(t_scene s, t_ray *r, int i)
{
    if (ft_boundaries_triangle(s, r, i))
        if (ft_get_point_triangle(s, r, i))
            return (1);
    return (0);
}
