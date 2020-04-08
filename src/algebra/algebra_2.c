#include "miniRT.h"

void	ft_normalise_vector(double *v)
{
	double mod;

	mod = ft_mod_vector(v);
	v[0] = v[0] / mod;
	v[1] = v[1] / mod;
	v[2] = v[2] / mod;
}

double	ft_mod_vector(double *v)
{
	return (sqrt(pow(v[0], 2.0) + pow(v[1], 2.0) + pow(v[2], 2.0)));
}

double	*ft_mtx_vct_prod(double **m, double *v, t_scene scene)
{
	double *p;
	int		i;
	(void)scene;

	i = 0;
	if (!(p = malloc(3 * sizeof(double))))
		return (0);
	while (i < 3)
	{
		p[i] = v[0] * m[0][i] + v[1] * m[1][i] + v[2] * m[2][i];
		i++;
	}
	return (p);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

double	ft_det(double	**m)
{
	double	det;

	det = (m[0][0] * m[1][1] * m[2][2] +
			m[1][0] * m[2][1] * m[0][2] +
			m[0][1] * m[1][2] * m[2][0]) - 
		(m[0][2] * m[1][1] * m[2][0] +
		 m[1][0] * m[0][1] * m[2][2] +
		 m[2][1] * m[1][2] * m[0][0]);
	return (det);
}
