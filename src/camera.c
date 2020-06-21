#include "miniRT.h"

t_vector        ft_local_camera_ray(t_scene s, double p_x, double p_y)
{
	t_vector c_local;
        double  sx;
        double  sy;

        sx = (double)s.x;
        sy = (double)s.y;
	c_local.x = (2 * ((p_x + 0.5) / sx) - 1) * (sx / sy)
		* s.camera[s.i_cam]->fov;
	c_local.y = (1 - 2 * ((p_y + 0.5) / sy))
		* s.camera[s.i_cam]->fov;
	c_local.z = -1;
	return (c_local);
}

int	        ft_global_camera_base(t_scene *s, int i_cam)
{
        t_matrix        conversion;

        if (!s->camera[i_cam])
            return (0);
	conversion.vx = ft_set_hor_axis(s->camera[i_cam]->n);
	conversion.vy = ft_cross_product(conversion.vx, s->camera[i_cam]->n);
        conversion.vz = ft_k_vct_prod(-1, s->camera[i_cam]->n);
	ft_normalize_vector(&conversion.vx);
	ft_normalize_vector(&conversion.vy);
	ft_normalize_vector(&conversion.vz);
        s->camera[i_cam]->base = conversion;
        return (1);
}
