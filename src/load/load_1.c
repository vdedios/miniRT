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
	ft_load_uint(&scene->x, buffer[1]);
	ft_load_uint(&scene->y, buffer[2]);
	ft_del_matrix(buffer);
}

void	ft_load_ambient(char *line, t_scene *scene)
{
	char		**buffer;
	int			i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(4);
	ft_load_udouble(&scene->ambient.intensity, buffer[1]);
	ft_load_rgb(&scene->ambient.rgb, buffer[2]);
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
	ft_load_coords(camera->pos, buffer[1]);
	ft_load_coords(camera->n, buffer[2]);
	ft_load_uint(&fov_deg, buffer[3]);
	camera->fov = ((double)fov_deg / 180) * M_PI;
        camera->base = NULL;
	ft_del_matrix(buffer);
}

void	ft_load_light(char *line, t_scene *scene)
{
	char	**buffer;
	int		i;
	t_light	*light;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	if (!(light = malloc(sizeof(t_light))))
		ft_error_handler(1);
	scene->light[scene->index[3] - 1] = light;
	scene->index[3]--;
	ft_load_coords(light->pos, buffer[1]);
	ft_load_udouble(&light->intensity, buffer[2]);
	ft_load_rgb(&light->rgb, buffer[3]);
	ft_del_matrix(buffer);
}
