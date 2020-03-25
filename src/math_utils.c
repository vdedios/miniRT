double	*ft_cross_product(double *u, double *v)
{
	double	*w;

	if (!(w = malloc(3 * sizeof(double))))
		return (0);
	w[0] = u[2]v[3] - u[3]v[2];
	w[1] = u[1]v[3] - u[3]v[1];
	w[2] = u[1]v[2] - u[2]v[1];
	return (w);
}

void	ft_normalise_vector(double *v)
{
	double mod;

	mod = sqrt(pow(v[0], 2.0) + pow(v[1], 2.0) + pow(v[2], 2.0));
	v[0] = v[0] / mod;
	v[1] = v[1] / mod;
	v[2] = v[2] / mod;
}
