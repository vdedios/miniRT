/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:17:01 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 23:24:11 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj_color	ft_disruption(t_light *light, t_obj_color obj)
{
	(void)light;
	obj.light = ft_parallel_light(light, obj);
	return (obj);
}
