#include "miniRT.h"

double	ft_ten_powerf(int p)
{
	double	t;
	int		i;

	t = 1;
	i = 0;
	if (p < 0)
	{
		p = -p;
		while (i++ < p)
			t = t / 10;
	}
	else if (p > 0)
		while (i++ < p)
			t = t * 10;
	return (t);
}

//REVISAR!!
double	ft_ftoi(char *str)
{
	int i;
	int	d;
	int	l;

	d = ft_atoi(str);
	while (*str != '.' && *str)
		str++;
	if (!*str)
		return ((double)d);
	str++;
	l = ft_strlen(str);
	i = ft_atoi(str);
	return ((double)(d + i * ft_ten_powerf(-l)));
}

int		ft_rgb_to_hex(char **rgb)
{
	int	num_r;
	int	num_g;
	int	num_b;

	num_r = ft_atoi(rgb[0]);
	num_g = ft_atoi(rgb[1]);
	num_b = ft_atoi(rgb[2]);
	return (num_b + (num_g << 8) + (num_r << 16));
}

void	ft_del_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}
