/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:55:59 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:09 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

double	ft_ftoi(char *str)
{
	int	k;
	int	d;
	int	l;
	int	i;

	i = 0;
	d = ft_atoi(str);
	while (str[i] != '.' && str[i])
		i++;
	if (!str[i])
		return ((double)d);
	i++;
	l = ft_strlen(&str[i]);
	k = ft_atoi(&str[i]);
	if (!d && str[0] == '-')
		k *= -1;
	return ((double)(d + k * ft_ten_powerf(-l)));
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
	int	i;

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

void	ft_get_triangle_boundaries(t_triangle *triangle)
{
	triangle->e0 = ft_sub_vector(triangle->b, triangle->a);
	triangle->e1 = ft_sub_vector(triangle->c, triangle->a);
	triangle->det = triangle->e0.x * triangle->e1.y
		- triangle->e0.y * triangle->e1.x;
	triangle->equation = 0;
	if (!triangle->det)
	{
		triangle->det = triangle->e0.y * triangle->e1.z
			- triangle->e1.y * triangle->e0.z;
		triangle->equation = 1;
	}
	if (!triangle->det)
	{
		triangle->det = triangle->e0.x * triangle->e1.z
			- triangle->e0.z * triangle->e1.x;
		triangle->equation = 2;
	}
}
