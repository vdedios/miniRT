#include "miniRT.h"

int     ft_parallel_light(char *option)
{
    if (option)
        if (!ft_strncmp(option, "--antialiasing", ft_strlen(option) + 1))
            return (1);
        else
            ft_error_handler(4);
    return (0);
}
