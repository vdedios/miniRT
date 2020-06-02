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

typedef struct	s_plane {
    double	point[3];
    double	n[3];
    int		rgb;
}		t_plane;

typedef struct  s_square {
    double	center[3];
    double	n[3];
    double	*dx;
    double	*dy;
    double	side;
    int		rgb;
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
    double	point[3]; 
    double	n[3];
    double	diameter;
    double	height;
    int		rgb;

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

#endif
