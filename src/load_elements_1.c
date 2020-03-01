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
	scene->id = 'R';
	ft_load_uint(&scene->x, buffer[1]);
	ft_load_uint(&scene->y, buffer[2]);
	ft_del_matrix(buffer);
}

void	ft_load_ambient(char *line, t_scene *scene)
{
	t_ambient	ambient;
	char		**buffer;
	int			i;
	//OJO! Crear y añadir nuevo nodo a la lista!
	(void)scene;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 3)
		ft_error_handler(4);
	ambient.id = 'A';
	ft_load_ufloat(&ambient.intensity, buffer[1]);
	ft_load_rgb(&ambient.rgb, buffer[2]);
	ft_del_matrix(buffer);
}

void	ft_load_camera(char *line, t_scene *scene)
{
	t_camera	camera;
	char 		**buffer;
	int			i;
	//OJO! Crear y añadir nuevo nodo a la lista!
	(void)scene;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	camera.id = 'c';
	ft_load_coords(camera.pos, buffer[1]);
	ft_load_coords(camera.n, buffer[2]);
	ft_load_uint(&camera.fov, buffer[3]);
	ft_del_matrix(buffer);
}

void	ft_load_light(char *line, t_scene *scene)
{
	t_light	light;
	char	**buffer;
	int		i;
	//OJO! Crear y añadir nuevo nodo a la lista!
	(void)scene;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	light.id = 'l';
	ft_load_coords(light.pos, buffer[1]);
	ft_load_ufloat(&light.intensity, buffer[2]);
	ft_load_rgb(&light.rgb, buffer[3]);
	ft_del_matrix(buffer);
}
