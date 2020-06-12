#include "miniRT.h"

void		ft_draw_element(t_scene scene, t_ray *ray)
{
    int     i;

    i = -1;
    while (scene.sphere[++i])
        ft_draw_sphere(scene, ray, i);
    i = -1;
    while (scene.plane[++i])
        ft_draw_plane(scene, ray, i);
    i = -1;
    while (scene.square[++i])
        ft_draw_square(scene, ray, i);
    i = -1;
    while (scene.triangle[++i])
        ft_draw_triangle(scene, ray, i);
    i = -1;
    while (scene.cylinder[++i])
        ft_draw_cylinder(scene, ray, i);
}

int		ft_render_scene(t_scene *s, int i_cam)
{
    int         px;
    int 	py;
    t_ray       ray;

    //---------------->Medición de rendimiento
    clock_t t; 
    t = clock(); 
    px = 0;
    ft_global_camera_base(s, i_cam);
    while (px < s->x)
    {
        py = 0;
        while (py < s->y)
        {
            ray.local = ft_local_camera_ray(*s, (double)px, (double)py);
            ray.global = ft_mtx_vct_prod(s->camera[i_cam]->base, ray.local);
            ray.t = DBL_MAX;
            ray.color = 0;
            ray.origin = (t_vector){0, 0, 0};
            ft_normalize_vector(&ray.global);
            ft_draw_element(*s, &ray);
            ft_fill_img_buf(&s->img, px, py, ray.color);
            py++;
        }
        px++;
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("Rendering took %f seconds to execute \n", time_taken); 
    //---------------------------------------<
    //
    ft_draw_reference(s->camera[i_cam]->base, s);
    return (0);
}
