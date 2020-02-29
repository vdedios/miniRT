#include "miniRT.h"

double	ft_ten_power(int p)
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
float	ft_ftoi(char *str)
{
	int i;
	int	d;
	int	l;

	d = ft_atoi(srt);
	while (*str != '.')
		str++;
	i = ft_atoi(srt);
	l = ft_strlen(str) - 1;
	return (d + i * ft_ten_power(-l));
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

int		ft_check_digit(char *info, char id)
{
	int i;

	i = 0;
	if (!info)
		return (0);
	while (info[i])
	{
		if (info[i] >= '0' && info[i] <= '9')
			i++;
		if (id == 'f')
			if (info[i] == '.')
				i++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_matrix(char **matrix, int start, int end, char type)
{
	while (start < end)
		if (!ft_check_digit(info[start++], type))
		{
			ft_del_matrix(matrix);
			return (0);
		}
	return (1);
}

int		ft_rgb_to_hex(char **rgb)
{
	int	num_r;
	int	num_g;
	int	num_b;

	num_r = ft_atoi(rgb[0]);
	num_g = ft_atoi(rgb[1]);
	num_b = ft_atoi(rgb[2]);
	return (num_b + (num_g << 4) + (num_r << 8))
}
