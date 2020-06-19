#include "miniRT.h"

void	ft_load_resolution(char *line, t_scene *scene)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(4);
	scene->x = ft_load_uint(buffer[1]);
	scene->y = ft_load_uint(buffer[2]);
        ft_check_system_resolution(scene);
	ft_del_matrix(buffer);
}

void	ft_load_ambient(char *line, t_scene *scene)
{
	char		**buffer;
	int		i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(4);
	scene->ambient.intensity = ft_load_udouble(buffer[1]);
	scene->ambient.rgb = ft_load_rgb(buffer[2]);
	ft_del_matrix(buffer);
}

void	ft_load_camera(char *line, t_scene *scene)
{
	char 	        **buffer;
	int	        i;
	int	        fov_deg;
	t_camera	*camera;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
	    i++;
	if (i != 4)
	    ft_error_handler(4);
	if (!(camera = malloc(sizeof(t_camera))))
	    ft_error_handler(1);
	scene->camera[scene->index[2] - 1] = camera;
	scene->index[2]--;
	camera->pos = ft_load_coords(buffer[1]);
	camera->n = ft_load_coords(buffer[2]);
	fov_deg = ft_load_uint(buffer[3]);
	camera->fov = tan(((double)fov_deg  * M_PI) / 360);
	ft_del_matrix(buffer);
}

void	ft_load_light(char *line, t_scene *scene)
{
	char	**buffer;
	int	i;
	t_light	*light;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3 + ft_bonus_option())
		ft_error_handler(4);
	if (!(light = malloc(sizeof(t_light))))
		ft_error_handler(1);
	scene->light[scene->index[3] - 1] = light;
	scene->index[3]--;
	light->pos = ft_load_coords(buffer[1]);
	light->intensity = ft_load_udouble(buffer[2]);
	light->rgb = ft_load_rgb(buffer[3]);
        light->parallel = ft_parallel_light(buffer[4]);
	ft_del_matrix(buffer);
}
