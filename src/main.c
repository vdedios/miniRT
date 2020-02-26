/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:31:14 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/25 19:49:23 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	//t_scene	scene;

	if (argc != 2)
		ft_printf("error, add the correct numbeer of args\n");
	else if (ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
	{
		//ft_scene_handler(argv[1], scene);
		ft_miniRT();
	}
	else if (!ft_strncmp(argv[1], "--save", ft_strlen(argv[1]) + 1))
		//ft_scene_to_bmp();
		ft_printf("convirtiendo escena a bmp!\n");
	else
		ft_printf("error, write a valid arg\n");
	return (0);
}
