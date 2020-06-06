#include "miniRT.h"

int		ft_intersect_plane(t_scene *s, t_auxplane *plane, t_ray *r)
{
    //ojo con esto siempre asigna desde abajo y hace la sombra desde abajo
    plane->n_aux = ft_k_vct_prod(1, plane->n);
    if (r->origin)
    {
        plane->po = ft_sub_vector(r->origin, plane->point);
        if (ft_dot_product(plane->n_aux, plane->po) < (-1 * FLT_EPSILON))
            return (1);
    }
    else
    {
        plane->p_l = ft_sub_vector(s->light[0]->pos, plane->point);
        plane->po = ft_sub_vector(s->camera[s->i_cam]->pos, plane->point);
        if (ft_dot_product(plane->p_l, plane->n_aux) < 0)
            ft_minus_vector(plane->n_aux);	
        if (ft_dot_product(plane->p_l,plane->n_aux)
                * ft_dot_product(plane->po,plane->n_aux) > 0
                && ft_dot_product(plane->n_aux, r->global) < 0)
            return (1);
    }
    return (0);
}

int             ft_get_point_plane(t_scene *s, t_auxplane *plane, t_ray *r)
{
    double t;

    if (r->origin)
        plane->qo = ft_sub_vector(plane->point, r->origin);
    else
        plane->qo = ft_sub_vector(plane->point, s->camera[s->i_cam]->pos);
    plane->den = ft_dot_product(r->global, plane->n_aux);
    plane->num = ft_dot_product(plane->qo, plane->n_aux);
    t = plane->num / plane->den;
    if (t > r->t && !r->origin)
        return (0);
    r->t = t + FLT_EPSILON;
    if (r->origin)
        plane->p= ft_add_vector(r->origin,
                ft_k_vct_prod(r->t, r->global));
    else
        plane->p= ft_add_vector(s->camera[s->i_cam]->pos,
                ft_k_vct_prod(r->t, r->global));
    return (1);
}

int		ft_draw_plane(t_scene s, t_ray *r, int i)
{
    t_auxplane auxplane;
    int         light_color; 
    int         r_c;
    int         g_c;
    int         b_c;

    auxplane.point = s.plane[i]->point;
    auxplane.n = s.plane[i]->n;
    if (ft_intersect_plane(&s, &auxplane, r))
        if (ft_get_point_plane(&s, &auxplane, r))
        {
            auxplane.l = ft_sub_vector(s.light[0]->pos, auxplane.p);
            light_color = (int)(s.light[0]->rgb * (1 - s.ambient.intensity))
                | (int)(s.ambient.rgb * s.ambient.intensity);
            r->color = ft_shading(s, auxplane.p, auxplane.n_aux, auxplane.l);
            //cambiar modelo sustractivo
            r_c = (((r->color & 0x00FF0000) >> 16) * ((s.plane[i]->rgb & 0x00FF0000) >> 16)) / 255;
            g_c = (((r->color & 0x0000FF00) >> 8) * ((s.plane[i]->rgb & 0x0000FF00) >> 8)) / 255;
            b_c = (((r->color & 0x000000FF)) * (s.plane[i]->rgb & 0x000000FF)) / 255;
            r->color = ((r_c << 16) + (g_c << 8) + b_c);
            return (1);
        }
    return (0);
}
