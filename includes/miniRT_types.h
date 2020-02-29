#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

typedef struct	s_window {
    void		*mlx_ptr;
    void		*win_ptr;
	int			button;
	int			x;
	int			y;
}				t_window;

typedef struct	s_scene {
	char		id;
	int			x;
	int			y;
	void		*next;
}				t_scene;

/*
** All elements that can be found in a scene
*/

//Elementos comunes y que necesitan de una función externa para tratarlos:
//-> rgb, atoi, ftoi (quitar comas, espacios y chequear errores de formato)
//Almacenado:
//-> una función por tipo
//
typedef struct	s_ambient {
	char		id;
	float		intensity;
	int			rgb;
	void		*next;
}				t_ambient;

typedef struct	s_camera {
	char		id;
	float		x;
	float		y;
	float		z;
	float		nx;
	float		ny;
	float		nz;
	float		fov;
}				t_camera;

typedef struct	s_light {
	char		id;
	float		x;
	float		y;
	float		z;
	float		intensity;
	int			rgb;
}				t_light;

typedef struct	s_sphere {
	char		id;
	float		x;
	float		y;
	float		z;
	float		diameter;
	int			rgb;
}				t_sphere;

typedef struct	s_plane {
	char		id;
	float		x;
	float		y;
	float		z;
	float		nx;
	float		ny;
	float		nz;
	int			rgb;
}				t_plane;

typedef struct	s_square {
	char		id;
	float		x;
	float		y;
	float		z;
	float		nx;
	float		ny;
	float		nz;
	float		side;
	int			rgb;
}				t_square;

typedef struct	s_cilinder {
	char		id;
	float		x;
	float		y;
	float		z;
	float		nx;
	float		ny;
	float		nz;
	float		diameter;
	float		height;
	int			rgb;
}				t_cilinder;

typedef struct	s_triangle {
	char		id;
	float		v1_x;
	float		v1_y;
	float		v1_z;
	float		v2_x;
	float		v2_y;
	float		v2_z;
	float		v3_x;
	float		v3_y;
	float		v3_z;
	int			rgb;
}				t_triangle;

#endif

