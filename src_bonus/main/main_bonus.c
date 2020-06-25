/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:03:09 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/25 13:44:03 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_assets(int option)
{
	int		fd;
	char	*line;

	if (option == 1)
		fd = open("assets/welcome.txt", O_RDONLY);
	else
		fd = open("assets/help.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		free(line);
	}
	ft_printf("%s\n", line);
	free(line);
	if (option == 2)
		exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_scene	scene;
	char	*aux;

	ft_assets(1);
	ft_initialize_options(&scene);
	if (argc == 2 && !ft_strncmp(argv[1], "--help", ft_strlen(argv[1]) + 1))
		ft_assets(2);
	if (argc > 1 && (aux = ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
			&& !(*(aux + 3)))
	{
		scene.window.mlx_ptr = mlx_init();
		ft_check_options(argc, argv, &scene);
		ft_load_scene(argv[1], &scene);
		if (scene.option[0])
			ft_scene_to_bmp(scene);
		else
			ft_minirt(scene);
	}
	else
		ft_error_handler(1);
	return (0);
}
