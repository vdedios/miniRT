#include "miniRT.h"

double	*ft_k_vct_prod(double k, double *v)
{
	int 	i;
	double	*w;

	i = 0;
	if (!(w = malloc( 3 * sizeof(double))))
		return (0);
	while (i < 3)
	{
		w[i] = k * v[i];
		i++;
	}
	return (w);
}

double	*ft_sub_vector(double *u, double *v)
{
	int 	i;
	double	*w;

	i = 0;
	if (!(w = malloc( 3 * sizeof(double))))
		return (0);
	while (i < 3)
	{
		w[i] = u[i] - v[i];
		i++;
	}
	return (w);
}

double	*ft_add_vector(double *u, double *v)
{
	int 	i;
	double	*w;

	i = 0;
	if (!(w = malloc( 3 * sizeof(double))))
		return (0);
	while (i < 3)
	{
		w[i] = u[i] + v[i];
		i++;
	}
	return (w);
}

double	ft_dot_product(double *u, double *v)
{
	int 	i;
	double	w;

	i = 0;
	w = 0;
	while (i < 3)
	{
		w = u[i] * v[i] + w;
		i++;
	}
	return (w);
}

double	*ft_cross_product(double *u, double *v)
{
	double	*w;

	if (!(w = malloc(3 * sizeof(double))))
		return (0);	
	w[0] = u[1] * v[2] - u[2] * v[1];
	w[1] = -1.0 * (u[0] * v[2] - u[2] * v[0]);
	w[2] = u[0] * v[1] - u[1] * v[0];
	return (w);
}

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
