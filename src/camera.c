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

void	ft_global_camera_base(t_scene *scene, int i_cam)
{
	double	**conversion;
	int 	i;

	i = 0;
	if (!(conversion = malloc(3 * sizeof(double *))))
            ft_error_handler(1);
	while (i < 3)
		if (!(conversion[i++] = malloc(3 * sizeof(double))))
                    ft_error_handler(1);
	i = -1;
	while (++i < 3)
		conversion[2][i] = -1.0 * scene->camera[i_cam]->n[i];
	ft_set_hor_axis(conversion[0], scene->camera[i_cam]->n);
	conversion[1] = ft_cross_product(conversion[0], scene->camera[i_cam]->n);
	ft_normalise_vector(conversion[0]);
	ft_normalise_vector(conversion[1]);
	ft_normalise_vector(conversion[2]);
        scene->camera[i_cam]->base = conversion;
}
