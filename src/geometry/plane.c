#include "miniRT.h"

int		ft_intersect_plane(t_scene *s, t_auxplane *plane, t_ray *r)
{
    if (ft_isvoid(r->origin))
        plane->po = ft_sub_vector(r->origin, plane->point);
    else
        plane->po = ft_sub_vector(s->camera[s->i_cam]->pos, plane->point);
    plane->den = ft_dot_product(plane->n, r->global);
    if (plane->den)
    {
        plane->num = ft_dot_product(plane->n, plane->po);
        if (plane->num * plane->den < 0)
            return (1);
    }
    return (0);
}

int             ft_get_point_plane(t_scene *s, t_auxplane *plane, t_ray *r)
{
    double t;

    t = -1 * (plane->num / plane->den);
    if (t > r->t && !ft_isvoid(r->origin))
        return (0);
    r->t = t + FLT_EPSILON;
    if (ft_isvoid(r->origin))
        plane->p = ft_add_vector(r->origin,
                ft_k_vct_prod(r->t, r->global));
    else
        plane->p = ft_add_vector(s->camera[s->i_cam]->pos,
                ft_k_vct_prod(r->t, r->global));
    return (1);
}

int		ft_draw_plane(t_scene s, t_ray *r, int i)
{
    t_auxplane  auxplane;
    t_obj_color obj;

    auxplane.point = s.plane[i]->point;
    auxplane.n = s.plane[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
        {
            if (auxplane.den > 0)
                auxplane.n = ft_k_vct_prod(-1, auxplane.n);
            obj.p = auxplane.p;
            obj.center = auxplane.point;
            obj.normal = auxplane.n;
            obj.rgb = s.plane[i]->rgb;
            r->color = ft_get_color(s, obj);
            return (1);
        }
    return (0);
}
