#include "miniRT.h"

//Aquí tener las funciones de traceray

//ESTA FUNCIÓN ES TEMPORAL Y VA A SER SUSTITUIDA POR EL PIPELINE
int		ft_draw_element(double *c_ray, t_scene scene, int *color)
{
	int	ret;

	//ret = ft_draw_sphere(c_ray, scene, color);
	//ret = ft_draw_plane(c_ray, scene, color);
	//ret = ft_draw_square(c_ray, scene, color);
	//ret = ft_draw_triangle(c_ray, scene, color);
	ret = ft_draw_cylinder(c_ray, scene, color);
	return (ret);
}

int		ft_draw_scene(t_scene scene, t_window *window)
{
	int 	p_x;
	int 	p_y;
	int		color;
	double	**c_base;
	double	*c_local_ray;
	double	*c_global_ray;

	p_x = 0;
	p_y = 0;
	c_base = ft_global_camera_base(scene);
	while (p_x < scene.x)
	{
		while (p_y < scene.y)
		{
			c_local_ray = ft_local_camera_ray(scene, p_x, p_y);
			c_global_ray = ft_mtx_vct_prod(c_base, c_local_ray, scene);
			ft_normalise_vector(c_global_ray);
			if (ft_draw_element(c_global_ray, scene, &color))
				mlx_pixel_put (window->mlx_ptr, window->win_ptr, p_x, p_y, color);
			p_y++;
		}
		p_y = 0;
		p_x++;
	}
	ft_draw_reference(c_base, scene, window);
	return (0);
}

int		ft_shading(double *v, double *u)
{
	double	shade;
	int		out;

	out = 0x000000E0;
	shade = ft_dot_product(u, v) /
		(ft_mod_vector(u) * ft_mod_vector(v));
	if (shade > 0 && shade < 1)
	{
		out = out * (1 - shade);
		return (out << 24);
	}
	return (0xE0000000);
}
