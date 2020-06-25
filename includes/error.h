/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:31:48 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/24 21:31:59 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** Error macros
*/

# define BAD_PATH 0
# define MEM_ALLOC 1
# define BAD_RGB 2
# define BAD_FLAG 3
# define BAD_INTENSITY 4
# define DOUBLE_FLAG 5
# define BAD_SCENE 6
# define BAD_BONUS 10
# define BAD_TEXTURE 11

/*
** Error functions
*/

void	ft_error_handler(int error_id);

#endif
