#include "miniRT.h"

void    ft_draw_center(t_axis_ref axis, t_scene *scene)
{
    axis.x = 40;
    axis.y = scene->y - 35;
    axis.color = 0x00ffff00;
    ft_fill_img_buf(&scene->img, axis.x, axis.y - 1, axis.color);
    ft_fill_img_buf(&scene->img, axis.x - 1, axis.y, axis.color);
    ft_fill_img_buf(&scene->img, axis.x, axis.y, axis.color);
    ft_fill_img_buf(&scene->img, axis.x + 1, axis.y, axis.color);
    ft_fill_img_buf(&scene->img, axis.x, axis.y + 1, axis.color);
}

void	ft_set_label_pos(t_axis_ref axis, char dir, t_scene *scene)
{
    if (dir == 'x')
    {
        scene->axis.x.x = axis.x + 2 * axis.px;
        scene->axis.x.y = axis.y - 2 * axis.py;
    }
    else if (dir == 'y')
    {
        scene->axis.y.x = axis.x + 2 * axis.px;
        scene->axis.y.y = axis.y - 2 * axis.py;
    }
    else if (dir == 'z')
    {
        scene->axis.z.x = axis.x + 2 * axis.px;
        scene->axis.z.y = axis.y - 2 * axis.py;
    }
}

void    ft_sketch_axis(t_axis_ref *axis, char dir, t_scene *scene)
{
    int i;

    if (dir == 'x')
        axis->color = 0x00ff0000;
    else if (dir == 'y')
        axis->color = 0x0000ff00;
    else if (dir == 'z')
        axis->color = 0x000000ff;
    while ((axis->x < (40 + axis->l_x) && axis->x > (40 - axis->l_x))
            || (axis->y < ((scene->y - 35) + axis->l_y)
                && axis->y > ((scene->y - 35) - axis->l_y)))
    {
        i = -1;
        while (i < 2)
        {
            ft_fill_img_buf(&scene->img, axis->x + i, axis->y, axis->color);
            ft_fill_img_buf(&scene->img, axis->x, axis->y + i, axis->color);
            ft_fill_img_buf(&scene->img, axis->x + i, axis->y + i, axis->color);
            i++;
        }
        axis->x = axis->x + axis->px;
        axis->y = axis->y - axis->py;
    }
}

void	ft_draw_axis(t_vector p, char dir, t_scene *scene)
{
    t_axis_ref      axis;

    ft_normalize_vector(&p);
    if (ft_abs(p.x) > 1e-4 && ft_abs(p.y) > 1e-4)
    {
        axis.px = (ft_abs(p.x) < ft_abs(p.y) ? 1 : ft_abs(p.x)
                / ft_abs(p.y)) * (p.x < 0 ? -1 : 1);
        axis.py = (ft_abs(p.y) < ft_abs(p.x) ? 1 : ft_abs(p.y)
                / ft_abs(p.x)) * (p.y < 0 ? -1 : 1);
    }
    else
    {
        axis.px = (ft_abs(p.x) < 1e-4 ? 0 : 1) * (p.x < 0 ? -1 : 1);
        axis.py = (ft_abs(p.y) < 1e-4 ? 0 : 1) * (p.y < 0 ? -1 : 1);
    }
    axis.x = 40;
    axis.y = scene->y - 35;
    axis.l_x = 35 * p.x * (p.x < 0 ? -1 : 1);
    axis.l_y = 35 * p.y * (p.y < 0 ? -1 : 1);
    ft_sketch_axis(&axis, dir, scene);
    ft_set_label_pos(axis, dir, scene);
    ft_draw_center(axis, scene);
}

void	ft_draw_reference(t_matrix c_base, t_scene *scene)
{
    t_vector        v;
    t_vector        p;
    t_matrix        base_inv;

    base_inv = ft_inv_matrix(c_base);
    v = ft_cross_product(c_base.vz, (t_vector){1, 0, 0});
    p = ft_cross_product(v, c_base.vz);
    p = ft_mtx_vct_prod(base_inv, p);
    ft_draw_axis(p, 'x', scene);
    v = ft_cross_product(c_base.vz, (t_vector){0, 1, 0});
    p = ft_cross_product(v, c_base.vz);
    p = ft_mtx_vct_prod(base_inv, p);
    ft_draw_axis(p, 'y', scene);
    v = ft_cross_product(c_base.vz, (t_vector){0, 0, 1});
    p = ft_cross_product(v, c_base.vz);
    p = ft_mtx_vct_prod(base_inv, p);
    ft_draw_axis(p, 'z', scene);
}
