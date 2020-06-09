#ifndef GEOMETRY_TYPES_H
# define GEOMETRY_TYPES_H

#include "scene_types.h"

/*
 ** Utils functions in a scene
 */

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

/*
 ** Geometries found in a scene
 */

typedef struct  s_sphere {
    t_vector	center;
    double	diameter;
    t_rgb       rgb;
    double	p_oc;
    double	d;
    t_vector	p;
    t_vector	l;
    t_vector	oc;
    t_vector	n;
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
    t_vector	dx;
    t_vector	dy;
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
    t_vector	l;
    t_vector	p;
    t_vector	n_aux;
    t_vector	qo;
    t_vector	pl;
    t_vector	po;
    t_vector	e0;
    t_vector	e1;
    t_vector	e2;
    t_vector	p0;
    t_vector	p1;
    t_vector	p2;
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
    t_vector	oc;
    t_vector	p;
    t_vector	center;
    t_vector	nsurface;
    t_vector	l;
}		t_cylinder;

typedef struct	s_auxplane {
    t_vector	point;
    t_vector	n;
    double	den;
    double	num;
    t_vector	l;
    t_vector	p;
    t_vector	n_aux;
    t_vector	qo;
    t_vector	p_l;
    t_vector	po;
}		t_auxplane;

#endif
