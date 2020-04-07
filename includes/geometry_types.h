#ifndef GEOMETRY_TYPES_H
# define GEOMETRY_TYPES_H

/*
** Geometries found in a scene
*/

typedef struct	s_sphere {
	double		center[3];
	double		diameter;
	int			rgb;
}				t_sphere;

typedef struct	s_plane {
	double		point[3];
	double		n[3];
	int			rgb;
}				t_plane;

typedef struct	s_square {
	double		center[3];
	double		n[3];
	double		*dx;
	double		*dy;
	double		side;
	int			rgb;
}				t_square;

typedef struct	s_triangle {
	double		a[3];
	double		b[3];
	double		c[3];
	int			rgb;
}				t_triangle;

typedef struct	s_cylinder {
	double		point[3]; //cambiar nombre a center
	double		n[3];
	double		diameter;
	double		height;
	int			rgb;
}				t_cylinder;

#endif
