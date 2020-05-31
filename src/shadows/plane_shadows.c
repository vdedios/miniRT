#include "miniRT.h"

int		ft_intersect_shadow_plane(t_auxplane *plane, t_ray *r)
{
    //falta aplicar que esté dentro de la distancia al foco de luz
    plane->n_aux = ft_k_vct_prod(1, plane->n);
    plane->po = ft_sub_vector(r->origin, plane->point);
    if (ft_dot_product(plane->n_aux, plane->po))
        return (1);
    return (0);
}

int             ft_shadow_plane(t_scene s, t_ray *r, int i)
{
    //falta calcular distancia punto-punto intersección
    t_auxplane auxplane;

    auxplane.point = s.plane[i]->point;
    auxplane.n = s.plane[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        return (1);
    return (0);
}
