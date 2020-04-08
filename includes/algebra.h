#ifndef ALGEBRA_H
# define ALGEBRA_H

#include "scene_types.h"
/*
** Linear algebra functions
*/

double	*ft_cross_product(double *u, double *v);
double	ft_dot_product(double *u, double *v);
void	ft_normalise_vector(double *v);
double	*ft_mtx_vct_prod(double **m, double *v, t_scene scene);
double	*ft_sub_vector(double *u, double *v);
double	*ft_add_vector(double *u, double *v);
double	ft_mod_vector(double *v);
double	*ft_k_vct_prod(double k, double *v);
double	ft_abs(double num);
double	**ft_inv_matrix(double	**m);
double	ft_det(double	**m);
int		ft_minus_vector(double *v);
double	*ft_set_axis(char axis);
void 	ft_set_hor_axis(double *x, double *n);

#endif
