#include "miniRT.h"

/*
   int             ft_intersect_caps(t_scene s, t_ray *r, int i)
   {
   t_auxplane auxplane;

   if (s.cylinder[i]->m > s.cylinder[i]->height)
   auxplane.point = ft_add_vector(s.cylinder[i]->point,
   ft_k_vct_prod(s.cylinder[i]->height, s.cylinder[i]->n));
   else
   auxplane.point = s.cylinder[i]->point;
   auxplane.n = s.cylinder[i]->n;
   if (ft_intersect_plane(&s, &auxplane, r))
   if (ft_get_point_plane(&s, &auxplane, r))
   if (ft_mod_vector(ft_sub_vector(auxplane.p, auxplane.point))
   < (s.cylinder[i]->diameter / 2))
   return (1);
   return (0);
   }
   */

int             ft_shadow_cylinder(t_scene s, t_ray *r, int i)
{
    if (ft_intersect_cylinder(&s, r, i))
    {
        s.cylinder[i]->p = ft_add_vector(r->origin,
                ft_k_vct_prod(r->t, r->global));
        if (ft_between_light_source(s.light[0]->pos, s.cylinder[i]->p, r->origin))
        {
            s.cylinder[i]->m = ft_dot_product(s.cylinder[i]->n,
                    ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->point));
            s.cylinder[i]->center = ft_add_vector(s.cylinder[i]->point,
                    ft_k_vct_prod(s.cylinder[i]->m, s.cylinder[i]->n));
            s.cylinder[i]->nsurface= ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->center);
            s.cylinder[i]->l = ft_sub_vector(s.light[0]->pos, s.cylinder[i]->p);
            if (s.cylinder[i]->m < s.cylinder[i]->height && s.cylinder[i]->m > 0)
                return (1);
        }
        /*
           s.cylinder[i]->m = ft_dot_product(s.cylinder[i]->n,
           ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->point));
           s.cylinder[i]->center = ft_add_vector(s.cylinder[i]->point,
           ft_k_vct_prod(s.cylinder[i]->m, s.cylinder[i]->n));
           s.cylinder[i]->nsurface= ft_sub_vector(s.cylinder[i]->p, s.cylinder[i]->center);
           s.cylinder[i]->l = ft_sub_vector(s.light[0]->pos, s.cylinder[i]->p);
           if (s.cylinder[i]->m > s.cylinder[i]->height || s.cylinder[i]->m < 0)
           return (ft_intersect_caps(s, r, i));
           */
    }
    return (0);
}
