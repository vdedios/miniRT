#include "miniRT.h"

int		ft_draw_element(t_scene scene, t_ray *ray)
{
//ESTA FUNCIÓN ES TEMPORAL Y VA A SER SUSTITUIDA POR EL PIPELINE
	int	ret;

        //COMPROBACIONES PREVIAS GEOMETRÍAS
	//ret = ft_draw_sphere(ray->global, scene, &ray->color);
	//ret = ft_draw_plane(c_ray, scene, color);
	//ret = ft_draw_square(c_ray, scene, color);
	//ret = ft_draw_triangle(c_ray, scene, color);
	ret = ft_draw_cylinder(ray->global, scene, &ray->color);
	return (ret);
}

int		ft_render_scene(t_scene *s, t_window *w,int i_cam)
{
	int 	px;
	int 	py;
        t_ray   ray;

	px = 0;
	py = 0;
	ft_global_camera_base(s, i_cam);
	while (px < s->x)
	{
		while (py < s->y)
		{
			ray.local = ft_local_camera_ray(*s, px, py);
			ray.global = ft_mtx_vct_prod(s->camera[i_cam]->base, ray.local);
			ft_normalise_vector(ray.global);
			if (ft_draw_element(*s, &ray))
                            ft_fill_img_buf(&s->img, px, py, ray.color);
                        else
                            ft_fill_img_buf(&s->img, px, py, 0x00000000);
			py++;
		}
                //Función para liberar el contenido del rayo y dejarlo todo a NULL
                //free(rayo)
		py = 0;
		px++;
	}
        //añadir al buffer y quitar los put_pixel
	ft_draw_reference(s->camera[i_cam]->base, s, w);
	return (0);
}

int		ft_shading(double *v, double *u)
{
    //Meter aquí la luz ambiente
    //Arreglar cuando no haya focos de luz que sólo devuelva el ambiente
	double	shade;
	int	out;

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
