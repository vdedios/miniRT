#include "miniRT.h"

t_vector        ft_local_camera_ray(t_scene s, int p_x, int p_y)
{
	t_vector c_local;

	//OJO: si no hay resolución de pantalla cuadrada la imagen se estira/comprime.
	//Arreglar esto.
        //Camera[0]?? -> chequear para cambio de cámara : he cambiado por icam
	c_local.x = (2 * ((p_x + 0.5) / s.x) - 1) * (s.x / s.y)
		* tan(s.camera[s.i_cam]->fov / 2);
	c_local.y = (1 - 2*((p_y + 0.5) / s.y))
                * tan(s.camera[s.i_cam]->fov / 2);
	c_local.z = -1;
	return (c_local);
}

void	ft_global_camera_base(t_scene *s, int i_cam)
{
        t_matrix        conversion;

	conversion.vx = ft_set_hor_axis(s->camera[i_cam]->n);
	conversion.vy = ft_cross_product(conversion.vx, s->camera[i_cam]->n);
        conversion.vz.x = -1.0 * s->camera[i_cam]->n.x;
        conversion.vz.y = -1.0 * s->camera[i_cam]->n.y;
        conversion.vz.z = -1.0 * s->camera[i_cam]->n.z;
	ft_normalize_vector(&conversion.vx);
	ft_normalize_vector(&conversion.vy);
	ft_normalize_vector(&conversion.vz);
        s->camera[i_cam]->base = conversion;
}
