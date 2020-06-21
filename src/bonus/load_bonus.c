#include "miniRT.h"

t_texture       ft_load_texture(t_scene *s, char *option)
{
    char	**buffer;
    int	        i;
    t_texture   texture;

    i = 0;
    buffer = ft_split(option, ':');
    while (buffer[i])
        i++;
    if (i != 2)
        ft_error_handler(4);
    texture.img = (int *)mlx_png_file_to_image(s->window.mlx_ptr, buffer[1]
            , &texture.width, &texture.height);
    texture.val = (int *)mlx_get_data_addr(texture.img, &texture.bitpixl,
            &texture.len, &texture.end);
    ft_del_matrix(buffer);
    return (texture);
}

t_bonus         ft_plane_bonus(t_scene *s, char *option)
{
    t_bonus     bonus;

    bonus.id = 0;
    if (option)
    {
        if (!ft_strncmp(option, "normal-disruption", ft_strlen(option) + 1))
            bonus.id = 1;
        else if (!ft_strncmp(option, "checkered", ft_strlen(option) + 1))
            bonus.id = 2;
        else if (!ft_strncmp(option, "bumpmap:", 8))
        {
            bonus.texture = ft_load_texture(s, option);
            bonus.id = 3;
        }
        else if (!ft_strncmp(option, "skybox:", 7))
        {
            bonus.texture = ft_load_texture(s, option);
            bonus.id = 4;
        }
        else
            ft_error_handler(4);
    }
    return (bonus);
}

t_bonus         ft_sphere_bonus(t_scene *s, char *option)
{
    t_bonus     bonus;

    bonus.id = 0;
    if (option)
    {
        if (!ft_strncmp(option, "rainbow", ft_strlen(option) + 1))
            bonus.id = 5;
        else if (!ft_strncmp(option, "uv-map:", 7))
        {
            bonus.texture = ft_load_texture(s, option);
            bonus.id = 6;
        }
        else
            ft_error_handler(4);
    }
    return (bonus);
}

t_bonus         ft_cylinder_bonus(char *option)
{
    t_bonus     bonus;

    bonus.id = 0;
    if (option)
    {
        if (!ft_strncmp(option, "rainbow", ft_strlen(option) + 1))
            bonus.id = 5;
        else
            ft_error_handler(4);
    }
    return (bonus);
}
