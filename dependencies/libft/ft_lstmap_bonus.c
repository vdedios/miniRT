/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:37:28 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/03 14:32:57 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list lst and applies the function f
** to the content of each element. Creates a new list
** resulting of the successive applications of the
** function f. The del function is here to delete the
** content of an element if needed
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*first_node;

	if (lst)
	{
		if (!(first_node = ft_lstnew(f(lst->content))))
			return (NULL);
		aux = first_node;
		lst = lst->next;
		while (lst)
		{
			if (!(aux->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&first_node, del);
				return (NULL);
			}
			aux = aux->next;
			lst = lst->next;
		}
		return (first_node);
	}
	return (NULL);
}
