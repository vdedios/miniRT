#include "miniRT.h"

void	ft_number_elements(char *line, int *count)
{
	if (line[0] == 'R' && line[1] == ' ')
		count[0]++;
	else if (line[0] == 'A' && line[1] == ' ')
		count[1]++;
	else if (line[0] == 'c' && line[1] == ' ')
		count[2]++;
	else if (line[0] == 'l' && line[1] == ' ')
		count[3]++;
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		count[4]++;
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		count[5]++;
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		count[6]++;
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		count[7]++;
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		count[8]++;
	else if (line[0] != '\0')
		ft_error_handler(4);	
}

void	ft_set_elements(t_scene *scene, int *count)
{
	if (count[0] != 1 || count[1] != 1)
		ft_error_handler(4);	
	if (!(scene.camera = malloc((count[2] + 1) * t_camera)))
		ft_error_handler(1);	
	scene->camera = NULL;
	if (!(scene.light = malloc((count[3] + 1) * t_light)))
		ft_error_handler(1);	
	scene->light = NULL;
	if (!(scene.sphere = malloc((count[4] + 1) * t_sphere)))
		ft_error_handler(1);	
	scene->sphere = NULL;
	if (!(scene.plane = malloc((count[5] + 1) * t_plane)))
		ft_error_handler(1);	
	scene->plane  = NULL;
	if (!(scene.square = malloc((count[6] + 1) * t_quare)))
		ft_error_handler(1);	
	scene->square  = NULL;
	if (!(scene.cylinder = malloc((count[7] + 1) * t_cylinder)))
		ft_error_handler(1);	
	scene->cylinder = NULL;
	if (!(scene.triangle = malloc((count[8] + 1) * t_triangle)))
		ft_error_handler(1);	
	scene->triangle = NULL;
}

void	ft_count_elements(char	*path, t_scene *scene)
{
	int		fd;
	int		count[9];
	char	*line;
	int 	i;
	
	i = 0;
	while (i < 9)
		count[i++] = 0;
	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		ft_error_handler(4);	
	ft_number_element(line, count);
	free (line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_number_element(line, count);
		free (line);
	}
	close (fd);
	ft_set_elements(scene, count);
}

void	ft_load_element(char *line, t_scene *scene)
{
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
	
	ft_count_elements(path, scene);
	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		ft_error_handler(4);	
	ft_load_element(line, elements);
	free (line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_load_element(line, elements);
		free (line);
	}
	//falta leer última linea?
}
