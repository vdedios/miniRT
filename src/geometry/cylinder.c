#include "miniRT.h"

int		ft_draw_cylinder(t_scene s, t_ray *r)
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    double m;
    double discr;
    double *oc;
    double *p;
    double *center;
    double *n;
    double *l;

    r->t = 0;
    oc = ft_sub_vector(s.camera[s.i_cam]->pos, s.cylinder[0]->point);
    a = 1 - pow(ft_dot_product(r->global, s.cylinder[0]->n), 2.0);
    b = 2 * (ft_dot_product(r->global, oc) - ft_dot_product(r->global, s.cylinder[0]->n)
            * ft_dot_product(oc, s.cylinder[0]->n));
    c = ft_dot_product(oc, oc) - pow(ft_dot_product(oc, s.cylinder[0]->n), 2.0)
        - pow((s.cylinder[0]->diameter / 2), 2.0);
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return (0);
    x1 = (- b + sqrt(discr)) / (2 * a);
    x2 = (- b - sqrt(discr)) / (2 * a);
    if (x1 > x2)
        r->t = x2;
    if (r->t < 0)
        r->t = x1;
    if (r->t < 0)
        return (0);
    p = ft_add_vector(s.camera[s.i_cam]->pos, ft_k_vct_prod(r->t, r->global));
    m = ft_dot_product(s.cylinder[0]->n, ft_sub_vector(p, s.cylinder[0]->point));
    center = ft_add_vector(s.cylinder[0]->point, ft_k_vct_prod(m, s.cylinder[0]->n));
    n = ft_sub_vector(p, center);
    l = ft_sub_vector(s.light[0]->pos, p);
    //tapas
    if (m > s.cylinder[0]->height || m < 0)
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

        if (m > s.cylinder[0]->height)
            ph = ft_add_vector(s.cylinder[0]->point,
                    ft_k_vct_prod(s.cylinder[0]->height, s.cylinder[0]->n));
        else
            ph = s.cylinder[0]->point;
        n_aux = ft_k_vct_prod(1, s.cylinder[0]->n);
        pl = ft_sub_vector(s.light[0]->pos, ph);
        po = ft_sub_vector(s.camera[s.i_cam]->pos, ph);
        if (ft_dot_product(pl, n_aux) < 0)
            ft_minus_vector(n_aux);	

        den = ft_dot_product(r->global, n_aux);
        if (ft_dot_product(pl,n_aux) * ft_dot_product(po,n_aux) > 0
                && ft_dot_product(n_aux, r->global) < 0)
        {
            qo = ft_sub_vector(ph, s.camera[s.i_cam]->pos);
            num = ft_dot_product(qo, n_aux);
            t = num / den;
            pp = ft_add_vector(s.camera[s.i_cam]->pos, ft_k_vct_prod(t, r->global));
            ll = ft_sub_vector(s.light[0]->pos, pp);
            if (ft_mod_vector(ft_sub_vector(pp, ph)) < (s.cylinder[0]->diameter / 2))
            {
                r->color = s.cylinder[0]->rgb | ft_shading(n_aux, ll);
                return (1);
            }
        }
        return (0);
    }
    else 
        r->color = s.cylinder[0]->rgb | ft_shading(n, l);
    return (1);
}
