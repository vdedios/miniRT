#include "miniRT.h"

void	ft_load_sphere(char *line, t_scene *scene)
{
	char		**buffer;
	int		i;
	t_sphere	*sphere;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	if (!(sphere = malloc(sizeof(t_sphere))))
		ft_error_handler(4);
	scene->sphere[scene->index[4] - 1] = sphere;
	scene->index[4]--;
	sphere->center = ft_load_coords(buffer[1]);
	sphere->diameter = ft_load_udouble(buffer[2]);
	sphere->rgb = ft_load_rgb(buffer[3]);
	ft_del_matrix(buffer);
}

void	ft_load_plane(char *line, t_scene *scene)
{
	char	**buffer;
	int	i;
	t_plane	*plane;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	if (!(plane = malloc(sizeof(t_plane))))
		ft_error_handler(4);
	scene->plane[scene->index[5] - 1] = plane;
	scene->index[5]--;
	plane->point = ft_load_coords(buffer[1]);
	plane->n = ft_load_coords(buffer[2]);
	plane->rgb = ft_load_rgb(buffer[3]);
	ft_del_matrix(buffer);
}

void	ft_load_square(char *line, t_scene *scene)
{
	char		**buffer;
	int		i;
	t_square	*square;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 5)
		ft_error_handler(4);
	if (!(square = malloc(sizeof(t_square))))
		ft_error_handler(4);
	scene->square[scene->index[6] - 1] = square;
	scene->index[6]--;
	square->center = ft_load_coords(buffer[1]);
	square->n = ft_load_coords(buffer[2]);
	square->side = ft_load_udouble(buffer[3]);
	square->rgb = ft_load_rgb(buffer[4]);
	square->dx = (t_vector){0, 0, 0};
	square->dy = (t_vector){0, 0, 0};
	ft_del_matrix(buffer);
}

void	ft_load_cylinder(char *line, t_scene *scene)
{
	char		**buffer;
	int		i;
	t_cylinder	*cylinder;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 6)
		ft_error_handler(4);
	if (!(cylinder = malloc(sizeof(t_cylinder))))
		ft_error_handler(4);
	scene->cylinder[scene->index[7] - 1] = cylinder;
	scene->index[7]--;
	cylinder->point = ft_load_coords(buffer[1]);
	cylinder->n = ft_load_coords(buffer[2]);
	cylinder->diameter = ft_load_udouble(buffer[3]);
	cylinder->height = ft_load_udouble(buffer[4]);
	cylinder->rgb = ft_load_rgb(buffer[5]);
	ft_del_matrix(buffer);
}

void	ft_load_triangle(char *line, t_scene *scene)
{
	char		**buffer;
	int		i;
	t_triangle	*triangle;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 5)
		ft_error_handler(4);
	if (!(triangle = malloc(sizeof(t_triangle))))
		ft_error_handler(4);
	scene->triangle[scene->index[8] - 1] = triangle;
	scene->index[8]--;
	triangle->a = ft_load_coords(buffer[1]);
	triangle->b = ft_load_coords(buffer[2]);
	triangle->c = ft_load_coords(buffer[3]);
	triangle->rgb = ft_load_rgb(buffer[4]);
	ft_del_matrix(buffer);
}
