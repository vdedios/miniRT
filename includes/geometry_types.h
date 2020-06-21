#ifndef GEOMETRY_TYPES_H
# define GEOMETRY_TYPES_H

#include "miniRT.h"

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
    double         r;
    double         g;
    double         b;
}		t_rgb;

typedef struct  s_slope{
    int         x;
    int         y;
}		t_slope;

typedef struct	        s_texture {
    void                *img;
    int                 *val;
    int                 width;
    int                 height;
    int                 len;
    int                 bitpixl;
    int                 end;
}		        t_texture;

typedef struct  s_bonus{
    int         id;
    t_texture   texture;
}		t_bonus;

typedef struct  s_obj_color{
    t_vector    p;
    t_vector    center;
    t_vector    normal;
    t_vector    light;
    t_vector    ray;
    t_rgb       rgb;
    t_bonus     bonus;
}		t_obj_color;

/*
** Geometries found in a scene
*/

typedef struct  s_sphere {
    t_vector	center;
    double	radius;
    t_rgb       rgb;
    double	p_oc;
    double	d;
    t_vector	p;
    t_vector	oc;
    t_vector	n;
    t_bonus     bonus;
}		t_sphere;

typedef struct	s_plane {
    t_vector	point;
    t_vector	n;
    t_rgb       rgb;
    t_bonus     bonus;
}		t_plane;

typedef struct  s_square {
    t_vector	n;
    t_vector	center;
    t_rgb       rgb;
    t_vector	dx;
    t_vector	dy;
    double	side;
    t_bonus     bonus;
}		t_square;

typedef struct	s_triangle {
    t_vector	a;
    t_vector	b;
    t_vector	c;
    t_rgb       rgb;
    double      det;
    char        equation;
    t_vector	e0;
    t_vector	e1;
    t_vector	e2;
    t_vector	p0;
    t_bonus     bonus;
}		t_triangle;

typedef struct	s_cylinder {
    t_vector	point;
    t_vector	n;
    t_rgb       rgb;
    double	radius;
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
    t_bonus     bonus;
}		t_cylinder;

typedef struct	s_auxplane {
    t_vector	point;
    t_vector	n;
    double	den;
    double	num;
    t_vector	l;
    t_vector	p;
    t_vector	po;
}		t_auxplane;

#endif
