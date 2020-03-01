#include "miniRT.h"

void	ft_load_element(char *line, t_scene *scene)
{
	//las escenas como mínimo tienen que tener resolución y tiene que ir lo primero
	if (line[0] == 'R' && line[1] == ' ')
		ft_load_resolution(line, scene);
	else if (line[0] == 'A' && line[1] == ' ')
		ft_load_ambient(line, scene);
	else if (line[0] == 'c' && line[1] == ' ')
		ft_load_camera(line, scene);
	else if (line[0] == 'l' && line[1] == ' ')
		ft_load_light(line, scene);
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		ft_load_sphere(line, scene);
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		ft_load_plane(line, scene);
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		ft_load_square(line, scene);
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		ft_load_cylinder(line, scene);
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		ft_load_triangle(line, scene);
	else if (line[0] != '\0')
		ft_error_handler(4);	
}

void	ft_load_scene(char	*path, t_scene *scene)
{
	int		fd;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		ft_error_handler(4);	
	ft_load_element(line, scene);
	free (line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_load_element(line, scene);
		free (line);
	}
}
