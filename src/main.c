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

void	ft_welcome(void)
{
    int	fd;
    char	*line;

    fd = open("art/welcome.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        ft_printf("%s\n", line);
        free (line);
    }
    ft_printf("%s\n", line);
    free (line);
}

int	main(int argc, char **argv)
{
    t_scene	scene;
    char        *aux;
    int         option;

    ft_welcome();
    ft_initialize_options(&scene);
    if (argc > 1 && (aux = ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
            && !(*(aux + 3)))
    {
        ft_load_scene(argv[1], &scene);
        if (!(option = ft_check_options(argc, argv, &scene)))
            ft_error_handler(1);
        else if (option == 2)
            ft_scene_to_bmp(scene);
        else 
            ft_miniRT(scene);
    }
    else
        ft_error_handler(1);
    return (0);
}
