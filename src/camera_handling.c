#include "miniRT.h"

double	*ft_local_camera_ray(t_scene scene, int p_x, int p_y)
{
	double	*c_local;

	if (!(c_local = malloc(4 * sizeof(double))))
		return (0);
	c_local[0] = (2*((p_x + 0.5) / scene.x) - 1) * (scene.x / scene.y)
		* tan(scene.camera[0]->fov);
	c_local[1] = (2*((p_y + 0.5) / scene.y) - 1) * (scene.x / scene.y)
		* tan(scene.camera[0]->fov);
	c_local[2] = -1;
	c_local[3] =  1;
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
	i = 0;
	while (i < 3)
	{
		conversion[2][i] = scene.camera[0]->n[i];
		i++;
	}
	conversion[0] = ft_cross_product(conversion[2], z);
	conversion[1] = ft_cross_product(conversion[2], conversion[0]);
	return (conversion);
}

int		ft_draw_scene(t_scene scene, t_window *window)
{
	int 	p_x;
	int 	p_y;
	double	**c_base;
	double	*c_local_ray;
	double	*c_global_ray;

	p_x = 10;
	p_y = 10;
	c_base = ft_global_camera_base(scene);
	while (p_x < scene.x)
	{
		while (p_y < scene.y)
		{
			c_local_ray = ft_local_camera_ray(scene, p_x, p_y);
			c_global_ray = ft_mtx_vct_prod(c_base, c_local_ray, scene);
			//normalizar
			mlx_pixel_put (window->mlx_ptr, window->win_ptr, p_x, p_y, 0x00FF0000);
			p_y++;
		}
		p_y = 0;
		p_x++;
	}
	//falta liberar memoria en algún punto
	return (0);
}
