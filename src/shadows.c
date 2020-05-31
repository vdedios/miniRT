#include "miniRT.h"

int             ft_between_light_source(double *point, double *origin, double *ray)
{
    double      *shadow_ray;
    double      mod_global;
    double      mod_shadow;
    double      angle;
    double      bias;

    bias = 0.0001;
    shadow_ray = ft_sub_vector(point, origin);
    mod_global = ft_mod_vector(ray);
    mod_shadow = ft_mod_vector(shadow_ray);
    angle = ft_dot_product(shadow_ray, ray)
        /(mod_global * mod_shadow);
    if (mod_shadow > bias && mod_shadow < mod_global
            && (angle < (1 + flt_epsilon)
                && angle > (1 - flt_epsilon)))
        return (1);
    return (0);
}

