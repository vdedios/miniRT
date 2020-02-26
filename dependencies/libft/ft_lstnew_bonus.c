/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:21:57 by vde-dios          #+#    #+#             */
/*   Updated: 2019/11/18 13:23:39 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a new
** element. The variable content is initialized with
** the value of the parameter content. The variable
** next is initialized to NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*new_element;

	if (!(new_element = malloc(sizeof(*new_element))))
		return (NULL);
	new_element->content = (void *)content;
	new_element->next = NULL;
	return (new_element);
}
