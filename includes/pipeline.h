#ifndef PIPELINE_H
# define PIPELINE_H

/*
** Ray tracing pipeline functions
*/

void		ft_render_scene(t_scene *scene);
void		ft_draw_element(t_scene scene, t_ray *ray);
void            ft_render_pxl(double px, double py, t_ray *ray, t_scene *s);
void            ft_fill_img_buf(t_image *img, int x, int y, int color);

#endif
