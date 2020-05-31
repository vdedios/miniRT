#include "miniRT.h"

int             ft_shadows(t_scene scene, t_ray *ray)
{
    int     i;

    i = -1;
    while (scene.sphere[++i])
        if (ft_shadow_sphere(scene, ray, i))
            return (1);
    i = -1;
    while (scene.plane[++i])
        if (ft_shadow_plane(scene, ray, i))
            return (1);
    i = -1;
    while (scene.square[++i])
        if (ft_shadow_square(scene, ray, i))
            return (1);
    i = -1;
    while (scene.triangle[++i])
        if (ft_shadow_triangle(scene, ray, i))
            return (1);
    i = -1;
    while (scene.cylinder[++i])
        if (ft_shadow_cylinder(scene, ray, i))
            return (1);
    return (0);
}

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
            && (angle < (1 + FLT_EPSILON)
                && angle > (1 - FLT_EPSILON)))
        return (1);
    return (0);
}
