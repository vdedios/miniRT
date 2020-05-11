#include "miniRT.h"

//Dividir las funciones en dos, una calcula el t, la otra el color
//Guardar color o ID para calcular después?

int		ft_draw_sphere(t_scene s, t_ray *r)
{
    t_sphere_rt sp;

    sp.oc = ft_sub_vector(s.sphere[0]->center, s.camera[0]->pos);
    sp.p_oc = ft_dot_product(sp.oc, r->global);
    sp.d = sqrt(pow(ft_mod_vector(sp.oc), 2.0) - pow(sp.p_oc, 2.0));
    if (sp.d > (s.sphere[0]->diameter / 2))
        return (0);
    r->t = sp.p_oc - sqrt(pow(s.sphere[0]->diameter / 2, 2.0) - pow(sp.d, 2.0));
    //Comparamos la t local calculada con la del rayo, si es mayor la guardamos, calculamos
    //color y lo almacenamos
    //A partir de aquí es calcular el color
    sp.p = ft_add_vector(s.camera[0]->pos, ft_k_vct_prod(r->t, r->global));
    sp.n = ft_sub_vector(sp.p, s.sphere[0]->center);
    sp.l = ft_sub_vector(s.light[0]->pos, sp.p);
    r->color = s.sphere[0]->rgb | ft_shading(sp.n, sp.l);
    return (1);
}

int		ft_draw_plane(double *c_ray, t_scene scene, int *color)
{
    t_plane_rt  pl;

    pl.n_aux = ft_k_vct_prod(1, scene.plane[0]->n);
    pl.p_l = ft_sub_vector(scene.light[0]->pos, scene.plane[0]->point);
    pl.po = ft_sub_vector(scene.camera[0]->pos, scene.plane[0]->point);
    if (ft_dot_product(pl.p_l, pl.n_aux) < 0)
        ft_minus_vector(pl.n_aux);	
    pl.den = ft_dot_product(c_ray, pl.n_aux);
    if (ft_dot_product(pl.p_l,pl.n_aux) * ft_dot_product(pl.po,pl.n_aux)
            > 0 && ft_dot_product(pl.n_aux, c_ray) < 0)
    {
        pl.qo = ft_sub_vector(scene.plane[0]->point, scene.camera[0]->pos);
        pl.num = ft_dot_product(pl.qo, pl.n_aux);
        pl.t = pl.num / pl.den;
        //Comparamos la t local calculada con la del rayo, si es mayor guardamos
        //A partir de aquí es calcular el color
        pl.p = ft_add_vector(scene.camera[0]->pos, ft_k_vct_prod(pl.t, c_ray));
        pl.l = ft_sub_vector(scene.light[0]->pos, pl.p);
        *color = scene.plane[0]->rgb | ft_shading(pl.n_aux, pl.l);
        return (1);
    }
    return (0);
}

int		ft_draw_square(double *c_ray, t_scene scene, int *color)
{
    int		i;
    double	t;
    double	den;
    double	num;
    double	*l;
    double	*p;
    double	*n_aux;
    double	*qo;
    double	*pl;
    double	*po;

    n_aux = ft_k_vct_prod(1, scene.square[0]->n);
    pl = ft_sub_vector(scene.light[0]->pos, scene.square[0]->center);
    po = ft_sub_vector(scene.camera[0]->pos, scene.square[0]->center);
    if (ft_dot_product(pl, n_aux) < 0)
        ft_minus_vector(n_aux);	
    den = ft_dot_product(c_ray, n_aux);
    i = -1;
    if (ft_dot_product(pl,n_aux) * ft_dot_product(po,n_aux)
            > 0 && ft_dot_product(n_aux, c_ray) < 0)
    {
        qo = ft_sub_vector(scene.square[0]->center, scene.camera[0]->pos);
        num = ft_dot_product(qo, n_aux);
        t = num / den;
        p = ft_add_vector(scene.camera[0]->pos, ft_k_vct_prod(t, c_ray));
        if (!scene.square[0]->dx)
        {
            //arreglar on perspectiva hacia arriba
            scene.square[0]->dx = ft_cross_product(n_aux, scene.camera[0]->n);
            if (!ft_mod_vector(scene.square[0]->dx))
                scene.square[0]->dx = ft_set_axis('x');
            scene.square[0]->dy = ft_cross_product(n_aux, scene.square[0]->dx);
            ft_normalise_vector(scene.square[0]->dx);
            ft_normalise_vector(scene.square[0]->dy);
        }
        if (ft_abs(ft_dot_product(scene.square[0]->dx,
                        ft_sub_vector(p, scene.square[0]->center))) > scene.square[0]->side ||
                ft_abs(ft_dot_product(scene.square[0]->dy,
                        ft_sub_vector(p, scene.square[0]->center))) > scene.square[0]->side)
            return (0);
        l = ft_sub_vector(scene.light[0]->pos, p);
        *color = scene.square[0]->rgb | ft_shading(n_aux, l);
        return (1);
    }
    return (0);
}

int		ft_draw_triangle(double *c_ray, t_scene scene, int *color)
{
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

    n = 0;
    e0 = ft_sub_vector(scene.triangle[0]->b, scene.triangle[0]->a);
    e1 = ft_sub_vector(scene.triangle[0]->c, scene.triangle[0]->b);
    e2 = ft_sub_vector(scene.triangle[0]->a, scene.triangle[0]->c);
    n_aux = ft_cross_product(e0, ft_sub_vector(scene.triangle[0]->c, scene.triangle[0]->a));
    pl = ft_sub_vector(scene.light[0]->pos, scene.triangle[0]->a);
    po = ft_sub_vector(scene.camera[0]->pos, scene.triangle[0]->a);
    if (ft_dot_product(pl, n_aux) < 0)
        n = ft_minus_vector(n_aux);
    den = ft_dot_product(c_ray,n_aux);
    i = -1;
    if (ft_dot_product(pl,n_aux) * ft_dot_product(po,n_aux)
            > 0 && ft_dot_product(n_aux, c_ray) < 0)
    {
        qo = ft_sub_vector(scene.triangle[0]->a, scene.camera[0]->pos);
        num = ft_dot_product(qo, n_aux);
        t = num / den;
        p = ft_add_vector(scene.camera[0]->pos, ft_k_vct_prod(t, c_ray));
        //computamos triángulo
        p0 = ft_sub_vector(p, scene.triangle[0]->a);
        p1 = ft_sub_vector(p, scene.triangle[0]->b);
        p2 = ft_sub_vector(p, scene.triangle[0]->c);
        if (n && (ft_dot_product(n_aux, ft_cross_product(e0, p0)) > 0
                    || ft_dot_product(n_aux, ft_cross_product(e1, p1)) > 0
                    || ft_dot_product(n_aux, ft_cross_product(e2, p2)) > 0))
            return (0);
        else if (!n && (ft_dot_product(n_aux, ft_cross_product(e0, p0)) < 0
                    || ft_dot_product(n_aux, ft_cross_product(e1, p1)) < 0
                    || ft_dot_product(n_aux, ft_cross_product(e2, p2)) < 0))
            return (0);
        //
        l = ft_sub_vector(scene.light[0]->pos, p);
        *color = scene.triangle[0]->rgb | ft_shading(n_aux, l);
        return (1);
    }
    return (0);
}

int		ft_draw_cylinder(double *c_ray, t_scene scene, int *color)
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    double t;
    double m;
    double discr;
    double *oc;
    double *p;
    double *center;
    double *n;
    double *l;

    t = 0;
    oc = ft_sub_vector(scene.camera[scene.i_cam]->pos, scene.cylinder[0]->point);
    a = 1 - pow(ft_dot_product(c_ray, scene.cylinder[0]->n), 2.0);
    b = 2 * (ft_dot_product(c_ray, oc) - ft_dot_product(c_ray, scene.cylinder[0]->n)
            * ft_dot_product(oc, scene.cylinder[0]->n));
    c = ft_dot_product(oc, oc) - pow(ft_dot_product(oc, scene.cylinder[0]->n), 2.0)
        - pow((scene.cylinder[0]->diameter / 2), 2.0);
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return (0);
    x1 = (- b + sqrt(discr)) / (2 * a);
    x2 = (- b - sqrt(discr)) / (2 * a);
    if (x1 > x2)
        t = x2;
    if (t < 0)
        t = x1;
    if (t < 0)
        return (0);
    p = ft_add_vector(scene.camera[scene.i_cam]->pos, ft_k_vct_prod(t, c_ray));
    m = ft_dot_product(scene.cylinder[0]->n, ft_sub_vector(p, scene.cylinder[0]->point));
    center = ft_add_vector(scene.cylinder[0]->point, ft_k_vct_prod(m, scene.cylinder[0]->n));
    n = ft_sub_vector(p, center);
    l = ft_sub_vector(scene.light[0]->pos, p);
    //tapas
    if (m > scene.cylinder[0]->height || m < 0)
    {
        double	t;
        double	den;
        double	num;
        double	*ll;
        double	*pp;
        double	*n_aux;
        double	*qo;
        double	*pl;
        double	*po;
        double	*ph;

        if (m > scene.cylinder[0]->height)
            ph = ft_add_vector(scene.cylinder[0]->point,
                    ft_k_vct_prod(scene.cylinder[0]->height, scene.cylinder[0]->n));
        else
            ph = scene.cylinder[0]->point;
        n_aux = ft_k_vct_prod(1, scene.cylinder[0]->n);
        pl = ft_sub_vector(scene.light[0]->pos, ph);
        po = ft_sub_vector(scene.camera[scene.i_cam]->pos, ph);
        if (ft_dot_product(pl, n_aux) < 0)
            ft_minus_vector(n_aux);	

        den = ft_dot_product(c_ray, n_aux);
        if (ft_dot_product(pl,n_aux) * ft_dot_product(po,n_aux) > 0
                && ft_dot_product(n_aux, c_ray) < 0)
        {
            qo = ft_sub_vector(ph, scene.camera[scene.i_cam]->pos);
            num = ft_dot_product(qo, n_aux);
            t = num / den;
            pp = ft_add_vector(scene.camera[scene.i_cam]->pos, ft_k_vct_prod(t, c_ray));
            ll = ft_sub_vector(scene.light[0]->pos, pp);
            if (ft_mod_vector(ft_sub_vector(pp, ph)) < (scene.cylinder[0]->diameter / 2))
            {
                *color = scene.cylinder[0]->rgb | ft_shading(n_aux, ll);
                return (1);
            }
        }
        return (0);
    }
    else 
        *color = scene.cylinder[0]->rgb | ft_shading(n, l);
    return (1);
}
