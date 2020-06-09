#include "miniRT.h"

t_matrix        ft_inv_matrix(t_matrix m)
{
    double	det;
    t_matrix inv;

    det = ft_det(m);
    inv.vx.x = (m.vy.y * m.vz.z - m.vy.z * m.vz.y) / det;
    inv.vx.y = -1 * (m.vx.y * m.vz.z - m.vx.z * m.vz.y) / det;
    inv.vx.z = (m.vx.y * m.vy.z - m.vx.z * m.vy.y) / det;
    inv.vy.x = -1 * (m.vy.x * m.vz.z - m.vy.z * m.vz.x) / det;
    inv.vy.y = (m.vx.x * m.vz.z - m.vx.z * m.vz.x) / det;
    inv.vy.z = -1 * (m.vx.x * m.vy.z - m.vx.z * m.vy.x) / det;
    inv.vz.x = (m.vy.x * m.vz.y - m.vy.y * m.vz.x) / det;
    inv.vz.y = -1 * (m.vx.x * m.vz.y - m.vx.y * m.vz.x) / det;
    inv.vz.z = (m.vx.x * m.vy.y - m.vx.y * m.vy.x) / det;
    return(inv);
}

//dejar como void?
int             ft_minus_vector(t_vect v)
{
    v.x = -1 * v.x;
    v.y = -1 * v.y;
    v.z = -1 * v.z;
    return (1);
}

t_vect          ft_set_axis(char axis)
{
    t_vect v;

    v.x = 0;
    v.y = 0;
    v.z = 0;
    if (axis == 'x')
        v.x = 1;
    else if (axis == 'y')
        v.y = 1;
    else if (axis == 'z')
        v.z = 1;
    return (v);
}

void            ft_set_hor_axis(t_vect x, t_vect n)
{
    if (!n.x && !n.y)
    {
        x.y = 0;
        x.z = 0;
        if (n.z > 0)
            x.x = -1;
        else if (n.z < 0)
            x.x = 1;
        else if (!n.z)
            ft_error_handler(4);
    }
    else
    {
        x.x = n.y;
        x.y = -1 * n.x;
        x.z = 0;
    }
}
