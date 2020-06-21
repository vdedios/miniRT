#include "miniRT.h"

/*
** SCENE OPTION INDEX: **

LIGHT
** parallel light -parallel ok!

PLANE/TRIANGLE/SQUARE
** bonus:1 | normal disruption - normal-disruption
** bonus:2 | checkered pattern -checkered
** bonus:3 | bumpmap texture -bumpmap
** bonus:4 | plane texture - skybox:textures/skybox.png

SPHERE
**  bonus:5 | color disruption -rainbow
**  bonus:6 | sphere texture - uv-map:texture/earth.png

CYLINDER
**  bonus:5 | color disruption -rainbow
*/

t_obj_color     ft_disruption(t_light *light, t_obj_color obj)
{
    if (obj.bonus.id == 1)
        obj.normal = ft_wave_normal(obj);
    else if (obj.bonus.id == 2)
        obj.rgb = ft_checkered_pattern(obj);
    else if (obj.bonus.id == 3)
        obj.normal = ft_bumpmap(obj);
    else if (obj.bonus.id == 4)
        obj.rgb = ft_plane_texture(obj);
    else if (obj.bonus.id == 5)
        obj.rgb = ft_rainbow_pattern(obj.normal, obj.rgb);
    else if (obj.bonus.id == 6)
        obj.rgb = ft_sphere_texture(obj);
    obj.light = ft_parallel_light(light, obj);
    return (obj);
}
