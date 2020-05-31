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

int		ft_render_scene(t_scene *s, t_window *w, int i_cam)
{
    int 	px;
    int 	py;
    t_ray   ray;

    px = 0;
    py = 0;
    ft_global_camera_base(s, i_cam);
    while (px < s->x)
    {
        while (py < s->y)
        {
            ray.local = ft_local_camera_ray(*s, px, py);
            ray.global = ft_mtx_vct_prod(s->camera[i_cam]->base, ray.local);
            ray.t = DBL_MAX;
            ray.color = 0;
            ray.origin = NULL;
            ft_normalise_vector(ray.global);
            ft_draw_element(*s, &ray);
            ft_fill_img_buf(&s->img, px, py, ray.color);
            py++;
        }
        //Función para liberar el contenido del rayo y dejarlo todo a NULL
        //free(rayo)
        py = 0;
        px++;
    }
    //añadir al buffer y quitar los put_pixel
    ft_draw_reference(s->camera[i_cam]->base, s, w);
    return (0);
}

int		ft_shading(t_scene s, double *p, double *v, double *u)
{
    //Meter aquí la luz ambiente
    //Arreglar cuando no haya focos de luz que sólo devuelva el ambiente
    double	shade;
    int	        out;
    t_ray       shadow;

    //cambiar el origen del shade al rayo
    shadow.global = u;
    shadow.origin = p;
    out = 0x000000E0;
    shade = ft_dot_product(u, v) /
        (ft_mod_vector(u) * ft_mod_vector(v));
    if (ft_shadows(s, &shadow))
        return (0xE0000000);
    if (shade > 0 && shade < 1)
    {
        out = out * (1 - shade);
        return (out << 24);
    }
    return (0xE0000000);
}
