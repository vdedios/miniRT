#include "miniRT.h"

void	ft_number_elements(char *line, t_scene *scene)
{
	if (line[0] == 'R' && line[1] == ' ')
		scene->index[0]++;
	else if (line[0] == 'A' && line[1] == ' ')
		scene->index[1]++;
	else if (line[0] == 'c' && line[1] == ' ')
		scene->index[2]++;
	else if (line[0] == 'l' && line[1] == ' ')
		scene->index[3]++;
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		scene->index[4]++;
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		scene->index[5]++;
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		scene->index[6]++;
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		scene->index[7]++;
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		scene->index[8]++;
	else if (line[0] != '\0')
		ft_error_handler(BAD_SCENE);	
}

void	ft_set_elements(t_scene *scene)
{
	if (scene->index[0] != 1 || scene->index[1] != 1)
		ft_error_handler(BAD_SCENE);	
	if (!(scene->camera = malloc((scene->index[2] + 1) * sizeof(t_camera *))))
		ft_error_handler(MEM_ALLOC);	
	scene->camera[scene->index[2]] = NULL;
	if (!(scene->light = malloc((scene->index[3] + 1) * sizeof(t_light *))))
		ft_error_handler(MEM_ALLOC);	
	scene->light[scene->index[3]] = NULL;
	if (!(scene->sphere = malloc((scene->index[4] + 1) * sizeof(t_sphere *))))
		ft_error_handler(MEM_ALLOC);	
	scene->sphere[scene->index[4]] = NULL;
	if (!(scene->plane = malloc((scene->index[5] + 1) * sizeof(t_plane *))))
		ft_error_handler(MEM_ALLOC);	
	scene->plane[scene->index[5]]  = NULL;
	if (!(scene->square = malloc((scene->index[6] + 1) * sizeof(t_square *))))
		ft_error_handler(MEM_ALLOC);	
	scene->square[scene->index[6]]  = NULL;
	if (!(scene->cylinder = malloc((scene->index[7] + 1) * sizeof(t_cylinder *))))
		ft_error_handler(MEM_ALLOC);	
	scene->cylinder[scene->index[7]] = NULL;
	if (!(scene->triangle = malloc((scene->index[8] + 1) * sizeof(t_triangle *))))
		ft_error_handler(MEM_ALLOC);	
	scene->triangle[scene->index[8]] = NULL;
}

void	ft_count_elements(char	*path, t_scene *scene)
{
	int	fd;
	char	*line;
	int 	i;
	
	i = 0;
	while (i < 9)
		scene->index[i++] = 0;
	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		ft_error_handler(BAD_PATH);	
	ft_number_elements(line, scene);
	free (line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_number_elements(line, scene);
		free (line);
	}
	close (fd);
	ft_set_elements(scene);
        scene->n_cams = scene->index[2];
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
		ft_error_handler(BAD_SCENE);	
}

void	ft_load_scene(char *path, t_scene *scene)
{
	int	fd;
	char	*line;
	
	ft_count_elements(path, scene);
	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		ft_error_handler(BAD_PATH);	
	ft_load_element(line, scene);
	free (line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_load_element(line, scene);
		free (line);
	}
}
