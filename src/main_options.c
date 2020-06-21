#include "miniRT.h"

void            ft_initialize_options(t_scene *scene)
{
    int i;

    i = -1;
    while (++i < 14)
        scene->option[i] = 0; 
}

static void     ft_bonus_options_added(char *argv, t_scene *scene)
{
    if (!ft_strncmp(argv, "--no-specular", ft_strlen(argv) + 1))
    {
        if (scene->option[4])
            ft_error_handler(4);
        scene->option[4] = 1;
    }
    else if (!ft_strncmp(argv, "--reference-axis", ft_strlen(argv) + 1))
    {
        if (scene->option[5])
            ft_error_handler(4);
        scene->option[5] = 1;
    }
    else
        ft_error_handler(4);
}

static void     ft_bonus_options(char *argv, t_scene *scene)
{
    if (!ft_strncmp(argv, "--sepia-filter", ft_strlen(argv) + 1))
    {
        if (scene->option[2])
            ft_error_handler(4);
        scene->option[2] = 1;
    }
    else if (!ft_strncmp(argv, "--antialiasing", ft_strlen(argv) + 1))
    {
        if (scene->option[3])
            ft_error_handler(4);
        scene->option[3] = 1;
    }
    else
        ft_bonus_options_added(argv, scene);
}

void            ft_save_option(char *argv, t_scene *scene)
{
    if (!ft_strncmp(argv, "--save", ft_strlen(argv) + 1))
    {
        if (scene->option[0])
            ft_error_handler(4);
        scene->option[0] = 1;
    }
    else
    {
#ifdef BONUS
        ft_bonus_options(argv, scene);
#else
        ft_error_handler(4);
#endif
    }
}

void             ft_check_options(int argc, char **argv, t_scene *scene)
{
    int i;

    i = 1;
    while (++i < argc)
        ft_save_option(argv[i], scene);
}
