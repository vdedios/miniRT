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
