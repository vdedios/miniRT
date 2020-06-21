#include "miniRT.h"

t_vector        ft_parallel_light(t_light *light, t_obj_color obj)
{
    t_vector    light_dir;
    t_vector    lp;
    //t_vector    aux;

    lp = ft_sub_vector(light->pos, obj.p);
    if (ft_isvoid(light->parallel))
    {
        light_dir = light->parallel;
        light_dir = ft_k_vct_prod(-1, light_dir);
        ft_normalize_vector(&light_dir);
        light->pos_shadow = ft_k_vct_prod(ft_dot_product(light_dir,lp)
                , light_dir);
    }
    else
    {
        light_dir = lp;
        light->pos_shadow = light->pos;
        ft_normalize_vector(&light_dir);
    }
    return (light_dir);
}
