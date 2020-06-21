#include "miniRT.h"

t_vector        ft_get_parallel_dir(char *option)
{
    char	**buffer;
    int	        i;
    t_vector    dir;

    i = 0;
    buffer = ft_split(option, ':');
    while (buffer[i])
        i++;
    if (i != 2)
        ft_error_handler(4);
    dir = ft_load_coords(buffer[1]);
    ft_normalize_vector(&dir);
    return (dir);
}

t_vector        ft_is_parallel_light(char *option)
{
    t_vector    dir;

    dir = (t_vector){0, 0, 0};
    if (option)
    {
        if (!ft_strncmp(option, "parallel:", 9))
            dir = ft_get_parallel_dir(option);
        else
            ft_error_handler(4);
    }
    return (dir);
}
