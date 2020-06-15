#include "miniRT.h"

void    ft_initialize_options(t_scene *scene)
{
    int i;

    i = -1;
    while (++i < 14)
        scene->option[i] = 0; 
}

int     ft_save_option(char *argv, t_scene *scene)
{
    if (!ft_strncmp(argv, "--save", ft_strlen(argv) + 1))
    {
        if (scene->option[0])
            return (0);
        scene->option[0] = 1;
        return (1);
    }
#ifdef BONUS
    if (!ft_strncmp(argv, "--normal-disruption", ft_strlen(argv) + 1))
    {
        if (scene->option[1])
            return (0);
        scene->option[1] = 1;
        return (1);
    }
    if (!ft_strncmp(argv, "--checkered-pattern", ft_strlen(argv) + 1))
    {
        if (scene->option[2])
            return (0);
        scene->option[2] = 1;
        return (1);
    }
    if (!ft_strncmp(argv, "--rainbow", ft_strlen(argv) + 1))
    {
        if (scene->option[3])
            return (0);
        scene->option[3] = 1;
        return (1);
    }
#endif
    return (0);
}

int    ft_check_options(int argc, char **argv, t_scene *scene)
{
    int i;
    int option;

    i = 1;
    while (++i < argc)
    {
        option = ft_save_option(argv[i], scene);
        if (!option)
            return (0);
    }
    if (scene->option[0])
        return (2);
    return (1);
}
