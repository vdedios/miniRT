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

int		ft_render_scene(t_scene *s, int i_cam)
{
    int         px;
    int 	py;
    int         i;
    int         j;
    t_ray       ray;
    t_rgb       color;

    px = 0;
    ft_global_camera_base(s, i_cam);
    while (px < s->x)
    {
        py = 0;
        while (py < s->y)
        {
            color = (t_rgb){0, 0, 0};
            i = 0;
            while(i < 2)
            {
                j = 0;
                while(j < 2)
                {
                    ray.local = ft_local_camera_ray(*s, (double)(px + (i + 0.5) / 2), (double)(py + (j + 0.5) / 2));
                    ray.global = ft_mtx_vct_prod(s->camera[i_cam]->base, ray.local);
                    ft_initialize_ray(&ray);
                    ft_normalize_vector(&ray.global);
                    ft_draw_element(*s, &ray);
                    color.r += (ray.color & 0x00FF0000 ) >> 16;
                    color.g += (ray.color & 0x0000FF00 ) >> 8;
                    color.b += (ray.color & 0x000000FF );
                    j++;
                }
                i++;
            }
            ray.color = ((int)(color.r / 4) << 16) + ((int)(color.g / 4) << 8) + (int)(color.b / 4);
            ft_fill_img_buf(&s->img, px, py, ray.color);
            py++;
        }
        px++;
    }
    ft_draw_reference(s->camera[i_cam]->base, s);
    return (0);
}
