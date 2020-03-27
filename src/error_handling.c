#include "miniRT.h"

void	ft_error_handler(int error_id)
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

void	ft_check_digit(char *info, char id)
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

/*
** This functions handle errors as well as save values. The input pointer 
** string must start with the searched value. It will first check format
** (spliting if necessary), then make pertinent conversion and saving values.
** If any error is encountered the function will exit with EXIT_FAILURE macro.
*/

void	ft_load_uint(int *num, char *buffer)
{
	ft_check_digit(buffer, 'd');
	*num = ft_atoi(buffer);
}

void	ft_load_udouble(double *num, char *buffer)
{
	ft_check_digit(buffer, 'f');
	*num = ft_ftoi(buffer);
}

//VOY A TENER PROBLEMAS CON LAS COMAS DOBLES
void	ft_load_coords(double *coord, char *buffer)
{
	int		i;
	char	**buff_aux;

	i = 0;
	buff_aux = ft_split(buffer, ',');
	while (buff_aux[i])
		ft_check_digit(buff_aux[i++], 'F');
	if (i != 3)
		ft_error_handler(4);
	i = -1;
	while (++i < 3)
		coord[i] = ft_ftoi(buff_aux[i]);
	ft_del_matrix(buff_aux);
}

void	ft_load_rgb(int *rgb, char *buffer)
{
	int		i;
	char	**buff_aux;

	i = 0;
	buff_aux = ft_split(buffer, ',');
	while (buff_aux[i])
		ft_check_digit(buff_aux[i++], 'd');
	if (i != 3)
		ft_error_handler(4);
	*rgb =	ft_rgb_to_hex(buff_aux); 
	ft_del_matrix(buff_aux);
}
