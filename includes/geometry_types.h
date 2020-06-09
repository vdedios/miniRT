#ifndef GEOMETRY_TYPES_H
# define GEOMETRY_TYPES_H

#include "scene_types.h"

/*
 ** Geometries found in a scene
 */

typedef struct  s_sphere {
    t_vector	center;
    double	diameter;
    t_rgb       rgb;
    double	p_oc;
    double	d;
    double	*p;
    double	*l;
    double	*oc;
    double	*n;
}		t_sphere;

typedef struct	s_plane {
    t_vector	point;
    t_vector	n;
    t_rgb       rgb;
}		t_plane;

typedef struct  s_square {
    t_vector	n;
    t_vector	center;
    t_rgb       rgb;
    double	*dx;
    double	*dy;
    double	side;
}		t_square;

typedef struct	s_triangle {
    t_vector	a;
    t_vector	b;
    t_vector	c;
    t_rgb       rgb;

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
    t_vector	point;
    t_vector	n;
    t_rgb       rgb;
    double	diameter;
    double	height;

    double      a;
    double      b;
    double      c;
    double      x1;
    double      x2;
    double      m;
    double      discr;
    double      *oc;
    double      *p;
    double      *center;
    double      *nsurface;
    double      *l;
}		t_cylinder;

/*
 ** Utils functions in a scene
 */

typedef struct	s_auxplane {
    double	*point;
    double	*n;
    double	den;
    double	num;
    double	*l;
    double	*p;
    double	*n_aux;
    double	*qo;
    double	*p_l;
    double	*po;
}		t_auxplane;

typedef struct  s_vector {
    double	x;
    double	y;
    double	z;
}		t_vector;

typedef struct  s_matrix {
    t_vector	vx;
    t_vector	vy;
    t_vector	vz;
}		t_matrix;

typedef struct  s_rgb {
    int         r;
    int         g;
    int         b;
}		t_rgb;

#endif
