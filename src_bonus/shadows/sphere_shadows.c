/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_shadows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:21:32 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:10 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadow_sphere(t_scene s, t_ray *r, int i)
{
	if (ft_intersect_sphere(&s, r, i))
	{
		r->t = s.sphere[i]->p_oc - sqrt(s.sphere[i]->radius
				* s.sphere[i]->radius
				- s.sphere[i]->d * s.sphere[i]->d);
		s.sphere[i]->p = ft_add_vector(r->origin,
				ft_k_vct_prod(r->t, r->global));
		if (ft_between_light_source(s.light[s.i_light]->pos_shadow
					, s.sphere[i]->p, r->origin))
			return (1);
	}
	return (0);
}
