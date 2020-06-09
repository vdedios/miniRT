#ifndef SCENE_TYPES_H
# define SCENE_TYPES_H

#include "geometry_types.h"

/*
** Elements needed to ray trace a scene
*/

typedef struct	s_window {
    void		*mlx_ptr;
    void		*win_ptr;
    int			button;
}			t_window;

typedef struct	s_image{
    void        *id;
    char        *addr;
    int         len;
    int         bitpixl;
    int         end;
}		t_image;

typedef struct	s_ambient {
	double	intensity;
	int	rgb;
}		t_ambient;

typedef struct	        s_camera {
	double		pos[3];
	double		n[3];
	double		fov;
        double          **base;
}			t_camera;

typedef struct	        s_light {
	double		pos[3];
	double		intensity;
	int		rgb;
}			t_light;

typedef struct	        s_ray {
	int		p_x;
	int 		p_y;
	double		*local;
	double		*global;
        int             color;
        double          t;
        double          *origin;
}		        t_ray;

typedef struct	        s_axis {
	int		x[2];
	int 		y[2];
	int 		z[2];
}		        t_axis;

/*
** SCENE INDEX:
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
	int		x;
	int		y;
	int		index[9];
        int             n_cams;
        int             i_cam;
        t_axis          axis;
        t_window        window;
        t_image         img;
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
