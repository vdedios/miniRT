#include "miniRT.h"

t_vector        ft_k_vct_prod(double k, t_vector v)
{
	t_vector	w;

        w.x = k * v.x;
        w.y = k * v.y;
        w.z = k * v.z;
	return (w);
}

t_vector        ft_sub_vector(t_vector u, t_vector v)
{
	t_vector w;

        w.x = u.x - v.x;
        w.y = u.y - v.y;
        w.z = u.z - v.z;
	return (w);
}

t_vector        ft_add_vector(t_vector u, t_vector v)
{
	t_vector w;

        w.x = u.x + v.x;
        w.y = u.y + v.y;
        w.z = u.z + v.z;
	return (w);
}

double          ft_dot_product(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector        ft_cross_product(t_vector u, t_vector v)
{
	t_vector w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = -1.0 * (u.x * v.z - u.z * v.x);
	w.z = u.x * v.y - u.y * v.x;
	return (w);
}
