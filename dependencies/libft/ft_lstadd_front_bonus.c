/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:24:33 by vde-dios          #+#    #+#             */
/*   Updated: 2019/11/18 13:25:21 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the beginning of the list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
		new->next = *alst;
	*alst = new;
}
