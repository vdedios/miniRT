#ifndef GEOMETRY_TYPES_H
# define GEOMETRY_TYPES_H

#include "scene_types.h"

/*
 ** Geometries found in a scene
 */

typedef struct  s_sphere {
    double	center[3];
    double	diameter;
    int		rgb;
    double	p_oc;
    double	d;
    double	*p;
    double	*l;
    double	*oc;
    double	*n;
}		t_sphere;

typedef struct	s_plane {
    double	point[3];
    double	n[3];
    int		rgb;
    double	t;
    double	den;
    double	num;
    double	*l;
    double	*p;
    double	*n_aux;
    double	*qo;
    double	*p_l;
    double	*po;
}		t_plane;

typedef struct  s_square {
    double	center[3];
    double	n[3];
    double	*dx;
    double	*dy;
    double	side;
    int		rgb;

    //i inutil?
    int		i;
    double	den;
    double	num;
    double	*l;
    double	*p;
    double	*n_aux;
    double	*qo;
    double	*pl;
    double	*po;
}		t_square;

typedef struct	s_triangle {
    double	a[3];
    double	b[3];
    double	c[3];
    int		rgb;

    //i inutil?
    int		i;
    int		n;
    double	t;
    double	den;
    double	num;
    double	*l;
    double	*p;
    double	*n_aux;
    double	*qo;
    double	*pl;
    double	*po;
    double	*e0;
    double	*e1;
    double	*e2;
    double	*p0;
    double	*p1;
    double	*p2;
}		t_triangle;

typedef struct	s_cylinder {
    double		point[3]; //cambiar nombre a center
    double		n[3];
    double		diameter;
    double		height;
    int			rgb;
}				t_cylinder;

#endif
