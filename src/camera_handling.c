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

//con esto calculamos matriz conversion para la cámara antes de empezar
//OJO coordenadas homogéneas!!
double	**ft_global_camera_base(t_scene scene)
{
	double	**conversion;
	int 	i;
	double	z[3];

	i = 0;
	z[0] = 0;
	z[1] = 0;
	z[2] = 1.0;
	if (!(conversion = malloc(3 * sizeof(double *))))
		return (0);
	while (i < 3)
		if (!(conversion[i++] = malloc(3 * sizeof(double))))
			return (0);
	i = -1;
	while (++i < 3)
		conversion[2][i] = -1.0 * scene.camera[0]->n[i];
	//Arreglar esto de una forma más elegante
	/*
	if (ft_dot_product(conversion[2], z))
	{
		conversion[0][0] = 1;
		conversion[0][1] = 0;
		conversion[0][2] = 0;
		conversion[1][0] = 0;
		conversion[1][1] = 1;
		conversion[1][2] = 0;

		return (conversion);
	}
	*/
	conversion[0] = ft_cross_product(scene.camera[0]->n, z);
	conversion[1] = ft_cross_product(scene.camera[0]->n, conversion[0]);
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
	double	t;
	double	den;
	double	num;
	double	*l;
	double	*p;
	double	*qo;

	den = ft_dot_product(c_ray, scene.plane[0]->n);
	//Un plano visto desde abajo???su normal
	//calcular bien los signos
	if (den > 1e-6)
	{
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

int		ft_draw_element(double *c_ray, t_scene scene, int *color)
{
	int	ret;

	//ret = ft_draw_sphere(c_ray, scene, color);
	ret = ft_draw_plane(c_ray, scene, color);
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
	//falta LIBERAR MEMORIA en algún punto
	return (0);
}
