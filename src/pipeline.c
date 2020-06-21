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

void            ft_fill_img_buf(t_image *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->len + x * (img->bitpixl / 8));
    *(unsigned int *)dst = color;
}

void            ft_initialize_ray(t_ray *ray)
{
    ray->t = DBL_MAX;
    ray->color = 0;
    ray->origin = (t_vector){0, 0, 0};
}

void            ft_render_pxl(double px, double py, t_ray *ray, t_scene *s)
{
    ray->local = ft_local_camera_ray(*s, px, py);
    ray->global = ft_mtx_vct_prod(s->camera[s->i_cam]->base, ray->local);
    ft_initialize_ray(ray);
    ft_normalize_vector(&ray->global);
    ft_draw_element(*s, ray);
}

void		ft_render_scene(t_scene *s)
{
    int         px;
    int 	py;
    t_ray       ray;

    px = 0;
    if (ft_global_camera_base(s, s->i_cam))
    {
        while (px < s->x)
        {
            py = 0;
            while (py < s->y)
            {
                if (s->option[3])
                    ft_render_pxl_antialiasing((double)px, (double)py, &ray, s);
                else
                    ft_render_pxl((double)px, (double)py, &ray, s);
                ft_fill_img_buf(&s->img, px, py, ray.color);
                py++;
            }
            px++;
        }
        ft_draw_reference(s->camera[s->i_cam]->base, s);
    }
}
