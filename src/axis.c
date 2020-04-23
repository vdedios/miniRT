#include "miniRT.h"

//Funciones de los ejes
void	ft_draw_axis(double *p, char axis, t_scene *scene, t_window *window)
{
	int x;
	int y;
	int l_x;
	int l_y;
	int px;
	int py;
	int color;
	int i;
        (void)window;

	if (ft_abs(p[0]) > 1e-4 && ft_abs(p[1]) > 1e-4)
	{
		px = (ft_abs(p[0]) < ft_abs(p[1]) ? 1 : ft_abs(p[0]) / ft_abs(p[1])) * (p[0] < 0 ? -1 : 1);
		py = (ft_abs(p[1]) < ft_abs(p[0]) ? 1 : ft_abs(p[1]) / ft_abs(p[0])) * (p[1] < 0 ? -1 : 1);
	}
	else
	{
		px = (ft_abs(p[0]) < 1e-4 ? 0 : 1) * (p[0] < 0 ? -1 : 1);
		py = (ft_abs(p[1]) < 1e-4 ? 0 : 1) * (p[1] < 0 ? -1 : 1);
	}

	x = 40;
	y = scene->y - 35;
	l_x = 35 * p[0] * (p[0] < 0 ? -1 : 1);
	l_y = 35 * p[1] * (p[1] < 0 ? -1 : 1);
	if (axis == 'x')
		color = 0x00FF0000;
	else if (axis == 'y')
		color = 0x0000FF00;
	else if (axis == 'z')
		color = 0x000000FF;
	while ((x < (40 + l_x) && x > (40 - l_x)) ||
			(y < ((scene->y - 35) + l_y) && y > ((scene->y - 35) - l_y)))
	{
		i = -1;
		while (i < 2)
		{
                        ft_fill_img_buf(&scene->img, x + i, y, color);
                        ft_fill_img_buf(&scene->img, x, y + i, color);
                        ft_fill_img_buf(&scene->img, x + i, y + i, color);
			i++;
		}
		x = x + px;
		y = y - py;
	}
	if (axis == 'x')
        {
                scene->axis.x[0] = x + 2 * px;
                scene->axis.x[1] = y - 2 * py;
		//mlx_string_put(window->mlx_ptr, window->win_ptr, x + 2 * px, y - 2 * py, color, "x");
        }
	else if (axis == 'y')
        {
                scene->axis.y[0] = x + 2 * px;
                scene->axis.y[1] = y - 2 * py;
		//mlx_string_put(window->mlx_ptr, window->win_ptr, x + 2 * px, y - 2 * py, color, "y");
        }
	else if (axis == 'z')
        {
                scene->axis.z[0] = x + 2 * px;
                scene->axis.z[1] = y - 2 * py;
		//mlx_string_put(window->mlx_ptr, window->win_ptr, x + 2 * px, y - 2 * py, color, "z");
        }
	x = 40;
	y = scene->y - 35;
	color = 0x00FFFF00;
        ft_fill_img_buf(&scene->img, x, y - 1, color);
        ft_fill_img_buf(&scene->img, x - 1, y, color);
        ft_fill_img_buf(&scene->img, x, y, color);
        ft_fill_img_buf(&scene->img, x + 1, y, color);
        ft_fill_img_buf(&scene->img, x, y + 1, color);
}

void	ft_draw_reference(double	**c_base, t_scene *scene, t_window *window)
{
	double	*v;
	double	*p;
	double	x[3];
	double	y[3];
	double	z[3];
	double	**base_inv;

	x[0] = 1;
	x[1] = 0;
	x[2] = 0;

	y[0] = 0;
	y[1] = 1;
	y[2] = 0;

	z[0] = 0;
	z[1] = 0;
	z[2] = 1;

	base_inv = ft_inv_matrix(c_base);
	v = ft_cross_product(c_base[2], x);
	p = ft_cross_product(v, c_base[2]);
	p = ft_mtx_vct_prod(base_inv, p);
	ft_draw_axis(p, 'x', scene, window);
	v = ft_cross_product(c_base[2], y);
	p = ft_cross_product(v, c_base[2]);
	p = ft_mtx_vct_prod(base_inv, p);
	ft_draw_axis(p, 'y', scene, window);

	v = ft_cross_product(c_base[2], z);
	p = ft_cross_product(v, c_base[2]);
	p = ft_mtx_vct_prod(base_inv, p);
	ft_draw_axis(p, 'z', scene, window);
}
