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
    ft_global_camera_base(s, i_cam);
    while (px < s->x)
    {
        py = 0;
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
        px++;
    }
    //añadir al buffer y quitar los put_pixel
    ft_draw_reference(s->camera[i_cam]->base, s, w);
    return (0);
}

int		ft_shading(t_scene s, double *p, double *v, double *u)
{
    double	shade;
    t_ray       shadow;
    int         r;
    int         g;
    int         b;
    double      a0;
    double      a1;

    ft_normalise_vector(u);
    ft_normalise_vector(v);
    shadow.global = u;
    shadow.origin = p;
    shade = ft_dot_product(u, v);
    if(ft_shadows(s, &shadow) || shade < 0)
        shade = 0;
    //Mezcla porcentual de colores
    a0 = s.ambient.intensity;
    a1 = s.light[0]->intensity;
    r = a0 * ((s.ambient.rgb & 0x00FF0000) >> 16)
            + a1 * shade * ((s.light[0]->rgb & 0x00FF0000) >> 16);
    if (r > 255)
        r = 255;
    g = a0 * ((s.ambient.rgb & 0x0000FF00) >> 8)
            + a1 * shade * ((s.light[0]->rgb & 0x0000FF00) >> 8);
    if (g > 255)
        g = 255;
    b = a0 * (s.ambient.rgb & 0x000000FF)
            + a1 * shade * (s.light[0]->rgb & 0x000000FF);
    if (b > 255)
        b = 255;
    return ((r << 16) + (g << 8) + b);
}
