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
	t_rgb	rgb;
}		t_ambient;

typedef struct	        s_camera {
	t_vector	pos;
	t_vector	n;
        t_matrix        base;
	double		fov;
}			t_camera;

typedef struct	        s_light {
	t_vector	pos;
	double		intensity;
	t_rgb		rgb;
}			t_light;

typedef struct	        s_ray {
	int		p_x;
	int 		p_y;
	t_vector	local;
	t_vector	global;
        t_vector        origin;
        int             color;
        double          t;
}		        t_ray;

typedef struct	        s_axis {
	t_vector	x;
	t_vector 	y;
	t_vector 	z;
}		        t_axis;

typedef struct	        s_axis_ref {
        int             x;
        int             y;
        int             l_x;
        int             l_y;
        int             px;
        int             py;
        int             color;
}		        t_axis_ref;

typedef struct	        s_texture {
    void                *img;
    int                 *val;
    int                 width;
    int                 height;
    int                 len;
    int                 bitpixl;
    int                 end;
}		        t_texture;

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

/*
** OPTION INDEX:
** 0 - save
** 1 - normal disruption
** 2 - checkered pattern
** 3 - bumpmap texture
** 4 - surface texture
** 5 - uv mapping
** 6 - parallel light
** 7 - sepia filter
** 8 - triangle
*/

typedef struct	s_scene {
        int             option[14];
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
        t_texture       texture;
}				t_scene;

#endif
