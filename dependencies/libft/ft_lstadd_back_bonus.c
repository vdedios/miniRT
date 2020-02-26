/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:26:01 by vde-dios          #+#    #+#             */
/*   Updated: 2019/11/18 13:27:03 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*aux;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{
			aux = ft_lstlast(*alst);
			aux->next = new;
		}
	}
}
