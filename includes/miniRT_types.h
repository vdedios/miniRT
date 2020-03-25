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

typedef struct	s_scene {
	int			x;
	int			y;
	t_ambient	ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_square	*square;
	t_cylinder	*cylinder;
	t_triangle	*triangle;
}				t_scene;

typedef struct	s_ambient {
	char		id;
	float		intensity;
	int			rgb;
}				t_ambient;

typedef struct	s_camera {
	char		id;
	float		pos[3];
	float		n[3];
	int			fov;
}				t_camera;

typedef struct	s_light {
	char		id;
	float		pos[3];
	float		intensity;
	int			rgb;
}				t_light;

typedef struct	s_sphere {
	char		id;
	float		center[3];
	float		diameter;
	int			rgb;
}				t_sphere;

typedef struct	s_plane {
	char		id;
	float		point[3];
	float		n[3];
	int			rgb;
}				t_plane;

typedef struct	s_square {
	char		id;
	float		center[3];
	float		n[3];
	float		side;
	int			rgb;
}				t_square;

typedef struct	s_cylinder {
	char		id;
	float		point[3];
	float		n[3];
	float		diameter;
	float		height;
	int			rgb;
}				t_cylinder;

typedef struct	s_triangle {
	char		id;
	float		a[3];
	float		b[3];
	float		c[3];
	int			rgb;
}				t_triangle;

#endif
