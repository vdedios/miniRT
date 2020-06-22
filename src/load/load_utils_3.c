#include "miniRT.h"

void	        ft_check_digit(char *info, char id)
{
	int i;

	i = 0;
	if (!info)
		ft_error_handler(BAD_SCENE);
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
			ft_error_handler(BAD_SCENE);
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
	int		i;
	int		comma;
	char	        **buff_aux;
        t_vector        vector;

	i = -1;
        comma = 0;
        while (buffer[++i])
            if (buffer[i] == ',')
                comma++;
	buff_aux = ft_split(buffer, ',');
	i = 0;
	while (buff_aux[i])
	    ft_check_digit(buff_aux[i++], 'F');
	if (i != 3 || comma != 2)
	    ft_error_handler(BAD_SCENE);
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
	    ft_error_handler(BAD_SCENE);
        color.r = (double)(ft_load_uint(buff_aux[0]));
        color.g = (double)(ft_load_uint(buff_aux[1]));
        color.b = (double)(ft_load_uint(buff_aux[2]));
        if (color.r > 255 || color.g > 255 || color.b > 255)
	    ft_error_handler(BAD_RGB);
	ft_del_matrix(buff_aux);
        return (color);
}
