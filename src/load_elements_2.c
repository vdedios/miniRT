#include "miniRT.h"

void	ft_load_sphere(char *line, t_scene *scene)
{
	char		**buffer;
	int			i;
	t_sphere	*sphere;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	if (!(sphere = malloc(sizeof(t_sphere))))
		ft_error_handler(4);
	sphere->id = 's';
	ft_load_coords(sphere->center, buffer[1]);
	ft_load_ufloat(&sphere->diameter, buffer[2]);
	ft_load_rgb(&sphere->rgb, buffer[3]);
	ft_lstadd_back(elements, ft_lstnew(sphere));
	ft_del_matrix(buffer);
}

void	ft_load_plane(char *line, t_scene *scene)
{
	char	**buffer;
	int		i;
	t_plane	*plane;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 4)
		ft_error_handler(4);
	if (!(plane = malloc(sizeof(t_plane))))
		ft_error_handler(4);
	plane->id = 'p';
	ft_load_coords(plane->point, buffer[1]);
	ft_load_coords(plane->n, buffer[2]);
	ft_load_rgb(&plane->rgb, buffer[3]);
	ft_lstadd_back(elements, ft_lstnew(plane));
	ft_del_matrix(buffer);
}

void	ft_load_square(char *line, t_scene *scene)
{
	char		**buffer;
	int			i;
	t_square	*square;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 5)
		ft_error_handler(4);
	if (!(square = malloc(sizeof(t_square))))
		ft_error_handler(4);
	square->id = 'q';
	ft_load_coords(square->center, buffer[1]);
	ft_load_coords(square->n, buffer[2]);
	ft_load_ufloat(&square->side, buffer[3]);
	ft_load_rgb(&square->rgb, buffer[4]);
	ft_lstadd_back(elements, ft_lstnew(square));
	ft_del_matrix(buffer);
}

void	ft_load_cylinder(char *line, t_scene *scene)
{
	char		**buffer;
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 6)
		ft_error_handler(4);
	if (!(cylinder = malloc(sizeof(t_cylinder))))
		ft_error_handler(4);
	cylinder->id = 'y';
	ft_load_coords(cylinder->point, buffer[1]);
	ft_load_coords(cylinder->n, buffer[2]);
	ft_load_ufloat(&cylinder->diameter, buffer[3]);
	ft_load_ufloat(&cylinder->height, buffer[4]);
	ft_load_rgb(&cylinder->rgb, buffer[5]);
	ft_lstadd_back(elements, ft_lstnew(cylinder));
	ft_del_matrix(buffer);
}

void	ft_load_triangle(char *line, t_scene *scene)
{
	char		**buffer;
	int			i;
	t_triangle	*triangle;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
		i++;
	if (i != 5)
		ft_error_handler(4);
	if (!(triangle = malloc(sizeof(t_triangle))))
		ft_error_handler(4);
	triangle->id = 't';
	ft_load_coords(triangle->a, buffer[1]);
	ft_load_coords(triangle->b, buffer[2]);
	ft_load_coords(triangle->c, buffer[3]);
	ft_load_rgb(&triangle->rgb, buffer[4]);
	ft_lstadd_back(elements, ft_lstnew(triangle));
	ft_del_matrix(buffer);
}
