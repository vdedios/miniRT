#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

typedef struct	s_window {
    void		*mlx_ptr;
    void		*win_ptr;
	int			button;
}				t_window;

/*
** All elements that can be found in a scene
*/

typedef struct	s_ambient {
	double		intensity;
	int			rgb;
}				t_ambient;

typedef struct	s_camera {
	double		pos[3];
	double		n[3];
	double		fov;
}				t_camera;

typedef struct	s_light {
	double		pos[3];
	double		intensity;
	int			rgb;
}				t_light;

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
	double		side;
	int			rgb;
}				t_square;

typedef struct	s_cylinder {
	double		point[3];
	double		n[3];
	double		diameter;
	double		height;
	int			rgb;
}				t_cylinder;

typedef struct	s_triangle {
	double		a[3];
	double		b[3];
	double		c[3];
	int			rgb;
}				t_triangle;

/*
** Scene index:
** 0 - scene
** 1 - ambient
** 2 - camera
** 3 - ligth
** 4 - sphere
** 5 - plane
** 6 - square
** 7 - cylinder
** 8 - triangle
*/

typedef struct	s_scene {
	int			x;
	int			y;
	int			index[9];
	t_ambient	ambient;
	t_camera	**camera;
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_square	**square;
	t_cylinder	**cylinder;
	t_triangle	**triangle;
}				t_scene;

#endif
