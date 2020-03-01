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

//ELIMINAR EL PRINTF DEL PROYECTO
int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		ft_error_handler(1);
	else if (ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
	{
		ft_load_scene(argv[1], &scene);
		ft_miniRT();
			//perror("<<ERROR>> wrong scene, please check format or path\n");
	}
	else if (!ft_strncmp(argv[1], "--save", ft_strlen(argv[1]) + 1))
	{
		ft_printf("converting scene to bmp...\n");
		//ft_scene_to_bmp();
		ft_printf("Saved!\n");

	}
	else
		ft_error_handler(1);
	return (0);
}
