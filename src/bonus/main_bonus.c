#include "miniRT.h"

void     ft_bonus_options_added(char *argv, t_scene *scene)
{
    if (!ft_strncmp(argv, "--no-specular", ft_strlen(argv) + 1))
    {
        if (scene->option[4])
            ft_error_handler(DOUBLE_FLAG);
        scene->option[4] = 1;
    }
    else if (!ft_strncmp(argv, "--reference-axis", ft_strlen(argv) + 1))
    {
        if (scene->option[5])
            ft_error_handler(DOUBLE_FLAG);
        scene->option[5] = 1;
    }
    else
        ft_error_handler(BAD_FLAG);
}

void     ft_bonus_options(char *argv, t_scene *scene)
{
    if (!ft_strncmp(argv, "--sepia-filter", ft_strlen(argv) + 1))
    {
        if (scene->option[2])
            ft_error_handler(DOUBLE_FLAG);
        scene->option[2] = 1;
    }
    else if (!ft_strncmp(argv, "--antialiasing", ft_strlen(argv) + 1))
    {
        if (scene->option[3])
            ft_error_handler(DOUBLE_FLAG);
        scene->option[3] = 1;
    }
    else
        ft_bonus_options_added(argv, scene);
}