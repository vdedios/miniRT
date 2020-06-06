#include "miniRT.h"

double	**ft_inv_matrix(double	**m)
{
	double	det;
	double	**i;
	int 	k;

	k = 0;
	if (!(i = malloc(3 * sizeof(double *))))
		return (0);
	while (k < 3)
		if (!(i[k++] = malloc(3 * sizeof(double))))
			return (0);
	det = ft_det(m);
	i[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
	i[0][1] = -1 * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) / det;
	i[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
	i[1][0] = -1 * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) / det;
	i[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
	i[1][2] = -1 * (m[0][0] * m[1][2] - m[0][2] * m[1][0]) / det;
	i[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
	i[2][1] = -1 * (m[0][0] * m[2][1] - m[0][1] * m[2][0]) / det;
	i[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
	return(i);
}

int	ft_minus_vector(double *v)
{
	v[0] = -1 * v[0];
	v[1] = -1 * v[1];
	v[2] = -1 * v[2];
	return (1);
}

double	*ft_set_axis(char axis)
{
	double	*v;
	
	if (!(v = malloc(3 * sizeof(double))))
		return (0);
	if (axis == 'x')
	{
		v[0] = 1;
		v[1] = 0;
		v[2] = 0;
	}
	else if (axis == 'y')
	{
		v[0] = 0;
		v[1] = 1;
		v[2] = 0;
	}
	else if (axis == 'z')
	{
		v[0] = 0;
		v[1] = 0;
		v[2] = 1;
	}
	return (v);
}

void 	ft_set_hor_axis(double *x, double *n)
{
	if (!n[0] && !n[1])
	{
		x[1] = 0;
		x[2] = 0;
		if (n[2] > 0)
			x[0] = -1;
		else if (n[2] < 0)
			x[0] = 1;
		else if (!n[2])
			ft_error_handler(4);
	}
	else
	{
		x[0] = n[1];
		x[1] = -1 * n[0];
		x[2] = 0;
	}
}
