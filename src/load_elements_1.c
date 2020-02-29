#include "miniRT.h"

int		ft_load_resolution(char *line, t_scene *scene)
{
	char	**info;

	info = ft_split(line, ' ');
	if (ft_check_matrix(info, 1, 3, 'd'))
		return (0);
	scene->id = 'R';
	scene->x = ft_atoi(info[1]);
	scene->y = ft_atoi(info[2]);
	ft_del_matrix(info);
	return (1);
}


int		ft_load_ambient(char *line, t_scene *scene)
{
	//OJO! Crear y añadir nuevo nodo a la lista!
	char		**info;
	char		**rgb;
	t_ambient	ambient;

	info = ft_split(line, ' ');
	if (ft_check_matrix(info, 1, 2, 'f'))
		return (0);
	rgb = ft_split(info[2], ',');
	if (ft_check_matrix(rgb, 0, 3, 'd'))
	{
		ft_del_matrix(info);
		return (0);
	}
	if (!(ambient = malloc(sizeof(t_ambient))))
		return (0);
	ambient->id = 'A';
	ambient->intensity = ft_ftoi(info[1]);
	ambient->rgb = ft_rgb_to_hex(rgb);
	ft_del_matrix(info);
	ft_del_matrix(rgb);
	return (1);
}
