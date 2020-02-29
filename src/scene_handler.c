#include "miniRT.h"

int		ft_load_element(char *line, t_scene *scene)
{
	int	exit;
	//las escenas como mínimo tienen que tener resolución y tiene que ir lo primero
	//Añadir funciones de error perror, fperror y macros como EXIT_SUCCESS
	exit = 0;
	if (line[0] == 'R' && line[1] == ' ')
		exit = ft_load_resolution(line, scene);
	else if (line[0] == 'A' && line[1] == ' ')
		exit = ft_load_ambient(line, scene);
	/*
	else if (line[0] == 'c' && line[1] == ' ')
		exit = ft_load_camera(line, scene);
	else if (line[0] == 'l' && line[1] == ' ')
		exit = ft_load_light(line, scene);
	else if (line[0] == 's' && line[1] == 'p' && line[1] == ' ')
		exit = ft_load_sphere(line, scene);
	else if (line[0] == 'p' && line[1] == 'l' && line[1] == ' ')
		exit = ft_load_plane(line, scene);
	else if (line[0] == 's' && line[1] == 'q' && line[1] == ' ')
		exit = ft_load_square(line, scene);
	else if (line[0] == 'c' && line[1] == 'y' && line[1] == ' ')
		exit = ft_load_cylinder(line, scene);
	else if (line[0] == 't' && line[1] == 'r' && line[1] == ' ')
		exit = ft_load_triangle(line, scene);
	*/
	return (exit);
}

int		ft_load_scene(char	*path, t_scene *scene)
{
	int		fd;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		return (0);
	if (!ft_load_element(line, scene))
		return (0);
	free (line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_load_element(line, scene))
			return (0);
		free (line);
	}
	get_next_line(fd, &line);
	free (line);
	return (1);
}
