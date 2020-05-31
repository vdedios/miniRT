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

int             ft_between_light_source(double *light, double *point, double *origin)
{
    double      *shadow_ray;
    double      *light_ray;
    double      mod_global;
    double      mod_shadow;
    double      angle;

    shadow_ray = ft_sub_vector(point, origin);
    light_ray = ft_sub_vector(light, origin);
    mod_shadow = ft_mod_vector(shadow_ray);
    mod_global = ft_mod_vector(light_ray);
    angle = ft_dot_product(shadow_ray, light_ray)
        /(mod_global * mod_shadow);
    if (mod_shadow > 0.0001 && mod_shadow < mod_global
            && (angle < (1 + FLT_EPSILON)
                && angle > (1 - FLT_EPSILON)))
        return (1);
    return (0);
}
