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
	if (!(scene = malloc(sizeof(t_scene))))
		ft_error_handler(1);
	ft_load_uint(&scene->x, buffer[1]);
	ft_load_uint(&scene->y, buffer[2]);
	ft_del_matrix(buffer);
}

void	ft_load_ambient(char *line, t_scene *scene)
{
	char		**buffer;
	int			i;
	t_ambient	*ambient;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(4);
	if (!(ambient = malloc(sizeof(t_ambient))))
		ft_error_handler(1);
	ft_load_ufloat(&scene->ambient->intensity, buffer[1]);
	ft_del_matrix(buffer);
}

void	ft_load_camera(char *line, t_scene *scene)
{
	char 		**buffer;
	int			i;
	t_camera	*camera;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	if (!(camera = malloc(sizeof(t_camera))))
		ft_error_handler(1);
	i = 0;
	while ((scene->camera + i))
		i++;
	ft_load_coords(camera->pos, buffer[1]);
	ft_load_coords(camera->n, buffer[2]);
	ft_load_uint(&camera->fov, buffer[3]);
	ft_lstadd_back(elements, ft_lstnew(camera));
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
	light->id = 'l';
	ft_load_coords(light->pos, buffer[1]);
	ft_load_ufloat(&light->intensity, buffer[2]);
	ft_load_rgb(&light->rgb, buffer[3]);
	ft_lstadd_back(elements, ft_lstnew(light));
	ft_del_matrix(buffer);
}
