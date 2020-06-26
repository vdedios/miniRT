/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:40:01 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/26 15:36:32 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __APPLE__
#  define ESC 53
#  define ARROW_RIGHT 124
#  define ARROW_LEFT 123
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14

# elif defined __unix__
#  define ESC 65307
#  define ARROW_RIGHT 65363
#  define ARROW_LEFT 65361
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_E 101
# endif

#endif
