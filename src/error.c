#include "miniRT.h"

/*
** This functions handle errors as well as save values. The input pointer 
** string must start with the searched value. It will first check format
** (spliting if necessary), then make pertinent conversion and saving values.
** If any error is encountered the function will exit with EXIT_FAILURE macro.
*/

void	        ft_error_handler(int error_id)
{
	errno = error_id;
	if (error_id == 1)
		perror("<<ERROR>> add the correct number of args");
	else if (error_id == 2)
		perror("<<ERROR>> write a valid arg");
	else if (error_id == 4)
		perror("<<ERROR>> wrong scene, please check format or path");
	exit(EXIT_FAILURE);
}

void	        ft_check_digit(char *info, char id)
{
	int i;

	i = 0;
	if (!info)
		ft_error_handler(4);
	while (info[i])
	{
		if (info[i] >= '0' && info[i] <= '9')
			i++;
		else if (id == 'f' && info[i] == '.')
			i++;
		else if (id == 'F' && (info[i] == '.'
				|| info[i] == '-'))
			i++;
		else
			ft_error_handler(4);
	}
}

int             ft_load_uint(char *buffer)
{
	ft_check_digit(buffer, 'd');
	return (ft_atoi(buffer));
}

double	        ft_load_udouble(char *buffer)
{
	ft_check_digit(buffer, 'f');
	return (ft_ftoi(buffer));
}

t_vector        ft_load_coords(char *buffer)
{
        //VOY A TENER PROBLEMAS CON LAS COMAS DOBLES, dos comas seguidas?
	int		i;
	char	        **buff_aux;
        t_vector        vector;

	i = 0;
	buff_aux = ft_split(buffer, ',');
	while (buff_aux[i])
	    ft_check_digit(buff_aux[i++], 'F');
	if (i != 3)
	    ft_error_handler(4);
	vector.x = ft_ftoi(buff_aux[0]);
	vector.y = ft_ftoi(buff_aux[1]);
	vector.z = ft_ftoi(buff_aux[2]);
	ft_del_matrix(buff_aux);
        return (vector);
}

t_rgb           ft_load_rgb(char *buffer)
{
	int	i;
	char	**buff_aux;
        t_rgb   color;

	i = 0;
	buff_aux = ft_split(buffer, ',');
	while (buff_aux[i])
	    ft_check_digit(buff_aux[i++], 'd');
	if (i != 3)
	    ft_error_handler(4);
        color.r = (double)(ft_load_uint(buff_aux[0]));
        color.g = (double)(ft_load_uint(buff_aux[1]));
        color.b = (double)(ft_load_uint(buff_aux[2]));
	ft_del_matrix(buff_aux);
        return (color);
}
