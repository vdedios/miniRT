/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_shadows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:22:24 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 22:04:10 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_shadow_square(t_scene s, t_ray *r, int i)
{
	t_auxplane	auxplane;

	auxplane.point = s.square[i]->center;
	auxplane.n = s.square[i]->n;
	if (ft_intersect_plane(&s, &auxplane, r))
		if (ft_get_point_plane(&s, &auxplane, r))
			if (ft_intersect_inside_square(s, &auxplane, i))
				if (ft_between_light_source(s.light[s.i_light]->pos
							, auxplane.p, r->origin))
					return (1);
	return (0);
}
