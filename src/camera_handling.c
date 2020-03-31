#include "miniRT.h"

double	*ft_local_camera_ray(t_scene scene, int p_x, int p_y)
{
	double	*c_local;

	if (!(c_local = malloc(3 * sizeof(double))))
		return (0);
	//OJO: si no hay resolución de pantalla cuadrada la imagen se estira/comprime.
	//Arreglar esto.
	c_local[0] = (2*((p_x + 0.5) / scene.x) - 1) * (scene.x / scene.y)
		* tan(scene.camera[0]->fov);
	c_local[1] = (1 - 2*((p_y + 0.5) / scene.y)) * tan(scene.camera[0]->fov);
	c_local[2] = -1;
	return (c_local);
}

void 	ft_set_hor_axis(double *x, double *n)
{
	if (!n[0] && !n[1])
	{
		x[1] = 0;
		x[2] = 0;
		if (n[2] > 0)
			x[0] = -1;
		else if (n[2] < 0)
			x[0] = 1;
		else if (!n[2])
			ft_error_handler(4);
	}
	else
	{
		x[0] = n[1];
		x[1] = -1 * n[0];
		x[2] = 0;
	}
}

double	**ft_global_camera_base(t_scene scene)
{
	double	**conversion;
	int 	i;

	i = 0;
	if (!(conversion = malloc(3 * sizeof(double *))))
		return (0);
	while (i < 3)
		if (!(conversion[i++] = malloc(3 * sizeof(double))))
			return (0);
	i = -1;
	while (++i < 3)
		conversion[2][i] = -1.0 * scene.camera[0]->n[i];
	ft_set_hor_axis(conversion[0], scene.camera[0]->n);
	conversion[1] = ft_cross_product(conversion[0], scene.camera[0]->n);
	ft_normalise_vector(conversion[0]);
	ft_normalise_vector(conversion[1]);
	ft_normalise_vector(conversion[2]);
	return (conversion);
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

int		ft_draw_sphere(double *c_ray, t_scene scene, int *color)
{
	double	p_oc;
	double	d;
	double	t;
	double	*p;
	double	*l;
	double	*oc;
	double	*n;

	oc = ft_sub_vector(scene.sphere[0]->center, scene.camera[0]->pos);
	p_oc = ft_dot_product(oc, c_ray);
	d = sqrt(pow(ft_mod_vector(oc), 2.0) - pow(p_oc, 2.0));
	if (d > (scene.sphere[0]->diameter / 2))
		return (0);
	t = p_oc - sqrt(pow(scene.sphere[0]->diameter / 2, 2.0) - pow(d, 2.0));
	p = ft_add_vector(scene.camera[0]->pos, ft_k_vct_prod(t, c_ray));
	n = ft_sub_vector(p, scene.sphere[0]->center);
	l = ft_sub_vector(scene.light[0]->pos, p);
	*color = scene.sphere[0]->rgb | ft_shading(n, l);
	return (1);
}

int		ft_draw_plane(double *c_ray, t_scene scene, int *color)
{
	int		i;
	double	t;
	double	den;
	double	num;
	double	*l;
	double	*p;
	double	*n_aux;
	double	*qo;
	double	*pl;
	double	*po;

	n_aux = ft_k_vct_prod(1, scene.plane[0]->n);
	pl = ft_sub_vector(scene.light[0]->pos, scene.plane[0]->point);
	po = ft_sub_vector(scene.camera[0]->pos, scene.plane[0]->point);
	if (ft_dot_product(pl, n_aux) < 0)
	{
		n_aux[0] = -1 * n_aux[0];
		n_aux[1] = -1 * n_aux[1];
		n_aux[2] = -1 * n_aux[2];
	}
	//po = ft_sub_vector(scene.camera[0]->pos, scene.plane[0]->point);
	den = ft_dot_product(c_ray, scene.plane[0]->n);
	i = -1;
	//Arreglar visión desde abajo!!
	if (ft_dot_product(pl,po) > 0 && ft_dot_product(n_aux, c_ray) < 0)
	{
		if (ft_dot_product(pl, scene.plane[0]->n) < 0)
			while (++i < 3)
				scene.plane[0]->n[i] = -1 * scene.plane[0]->n[i];
		qo = ft_sub_vector(scene.plane[0]->point, scene.camera[0]->pos);
		num = ft_dot_product(qo, scene.plane[0]->n);
		t = num / den;
		p = ft_add_vector(scene.camera[0]->pos, ft_k_vct_prod(t, c_ray));
		l = ft_sub_vector(scene.light[0]->pos, p);
		*color = scene.plane[0]->rgb | ft_shading(scene.plane[0]->n, l);
		return (1);
	}
	return (0);
}

int		ft_draw_square(double *c_ray, t_scene scene, int *color)
{
	int		i;
	double	t;
	double	den;
	double	num;
	double	*l;
	double	*p;
	double	*qo;
	double	*pl;
	double	*po;

	pl = ft_sub_vector(scene.light[0]->pos, scene.square[0]->center);
	po = ft_sub_vector(scene.camera[0]->pos, scene.square[0]->center);
	den = ft_dot_product(c_ray, scene.square[0]->n);
	i = -1;
	if ( ft_dot_product(pl,po) > 0 && ft_dot_product(pl, c_ray) < 0)
	{
		if (ft_dot_product(pl, scene.square[0]->n) < 0)
			while (++i < 3)
				scene.square[0]->n[i] = -1 * scene.square[0]->n[i];
		qo = ft_sub_vector(scene.square[0]->center, scene.camera[0]->pos);
		num = ft_dot_product(qo, scene.square[0]->n);
		t = num / den;
		p = ft_add_vector(scene.camera[0]->pos, ft_k_vct_prod(t, c_ray));
		if (!scene.square[0]->dx)
		{
			//scene.square[0]->dx = ft_sub_vector(scene.square[0]->center, p);
			//Arreglar visión desde abajo!!
			//esta es opción valida??
			scene.square[0]->dx = ft_cross_product(scene.square[0]->n, scene.camera[0]->n);
			scene.square[0]->dy = ft_cross_product(scene.square[0]->n, scene.square[0]->dx);
			ft_normalise_vector(scene.square[0]->dx);
			ft_normalise_vector(scene.square[0]->dy);
		}
		if (ft_abs(ft_dot_product(scene.square[0]->dx,
			ft_sub_vector(p, scene.square[0]->center))) > scene.square[0]->side ||
			ft_abs(ft_dot_product(scene.square[0]->dy,
			ft_sub_vector(p, scene.square[0]->center))) > scene.square[0]->side)
			return (0);
		l = ft_sub_vector(scene.light[0]->pos, p);
		*color = scene.square[0]->rgb | ft_shading(scene.square[0]->n, l);
		return (1);
	}
	return (0);
}

int		ft_draw_element(double *c_ray, t_scene scene, int *color)
{
	int	ret;

	//ret = ft_draw_sphere(c_ray, scene, color);
	ret = ft_draw_plane(c_ray, scene, color);
	//ret = ft_draw_square(c_ray, scene, color);
	return (ret);
}

void	ft_draw_axis(double *p, char axis, t_scene scene, t_window *window)
{
	int x;
	int y;
	int l_x;
	int l_y;
	int px;
	int py;
	int color;
	int i;

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
	y = scene.y - 35;
	l_x = 35 * p[0] * (p[0] < 0 ? -1 : 1);
	l_y = 35 * p[1] * (p[1] < 0 ? -1 : 1);
	if (axis == 'x')
		color = 0x00FF0000;
	else if (axis == 'y')
		color = 0x0000FF00;
	else if (axis == 'z')
		color = 0x000000FF;
	while ((x < (40 + l_x) && x > (40 - l_x)) ||
			(y < ((scene.y - 35) + l_y) && y > ((scene.y - 35) - l_y)))
	{
		i = -1;
		while (i < 2)
		{
			mlx_pixel_put (window->mlx_ptr, window->win_ptr, x + i, y, color);
			mlx_pixel_put (window->mlx_ptr, window->win_ptr, x, y + i, color);
			mlx_pixel_put (window->mlx_ptr, window->win_ptr, x + i, y + i, color);
			i++;
		}
		x = x + px;
		y = y - py;
	}

	if (axis == 'x')
		mlx_string_put(window->mlx_ptr, window->win_ptr, x + 2 * px, y - 2 * py, color, "x");
	else if (axis == 'y')
		mlx_string_put(window->mlx_ptr, window->win_ptr, x + 2 * px, y - 2 * py, color, "y");
	else if (axis == 'z')
		mlx_string_put(window->mlx_ptr, window->win_ptr, x + 2 * px, y - 2 * py, color, "z");
	x = 40;
	y = scene.y - 35;
	color = 0x00FFFF00;
	mlx_pixel_put (window->mlx_ptr, window->win_ptr, x, y - 1, color);
	mlx_pixel_put (window->mlx_ptr, window->win_ptr, x - 1, y, color);
	mlx_pixel_put (window->mlx_ptr, window->win_ptr, x, y, color);
	mlx_pixel_put (window->mlx_ptr, window->win_ptr, x + 1, y, color);
	mlx_pixel_put (window->mlx_ptr, window->win_ptr, x, y + 1, color);
}

void	ft_draw_reference(double	**c_base, t_scene scene, t_window *window)
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
	p = ft_mtx_vct_prod(base_inv, p, scene);
	ft_draw_axis(p, 'x', scene, window);
	v = ft_cross_product(c_base[2], y);
	p = ft_cross_product(v, c_base[2]);
	p = ft_mtx_vct_prod(base_inv, p, scene);
	ft_draw_axis(p, 'y', scene, window);

	v = ft_cross_product(c_base[2], z);
	p = ft_cross_product(v, c_base[2]);
	p = ft_mtx_vct_prod(base_inv, p, scene);
	ft_draw_axis(p, 'z', scene, window);
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
	//Pintamos los ejes de referencia abajo en la esquina inferior izquierda
	ft_draw_reference(c_base, scene, window);
	//falta LIBERAR MEMORIA en algún punto
	return (0);
}
