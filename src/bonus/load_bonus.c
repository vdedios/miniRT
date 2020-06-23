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
        ft_error_handler(BAD_BONUS);
    if (!(texture.img = (int *)mlx_png_file_to_image(s->window.mlx_ptr, buffer[1]
            , &texture.width, &texture.height)))
        ft_error_handler(BAD_TEXTURE);
    texture.val = (int *)mlx_get_data_addr(texture.img, &texture.bitpixl,
            &texture.len, &texture.end);
    ft_del_matrix(buffer);
    return (texture);
}

t_bonus         ft_plane_bonus(t_scene *s, char **option)
{
    t_bonus     bonus;
    int         i;

    bonus.id[0] = 0;
    i = -1;
    while (option[++i])
    {
        if (!ft_strncmp(option[i], "normal-disruption", ft_strlen(option[i]) + 1))
            bonus.id[i] = 1;
        else if (!ft_strncmp(option[i], "checkered", ft_strlen(option[i]) + 1))
            bonus.id[i] = 2;
        else if (!ft_strncmp(option[i], "bumpmap:", 8))
        {
            bonus.bumpmap = ft_load_texture(s, option[i]);
            bonus.id[i] = 3;
        }
        else if (!ft_strncmp(option[i], "skybox:", 7))
        {
            bonus.texture = ft_load_texture(s, option[i]);
            bonus.id[i] = 4;
        }
        else
            ft_error_handler(BAD_BONUS);
    }
    return (bonus);
}

t_bonus         ft_sphere_bonus(t_scene *s, char **option)
{
    t_bonus     bonus;
    int         i;

    bonus.id[0] = 0;
    i = -1;
    bonus.type = 's';
    while (option[++i])
    {
        if (!ft_strncmp(option[i], "rainbow", ft_strlen(option[i]) + 1))
            bonus.id[i] = 5;
        else if (!ft_strncmp(option[i], "uv-map:", 7))
        {
            bonus.texture = ft_load_texture(s, option[i]);
            bonus.id[i] = 6;
        }
        else if (!ft_strncmp(option[i], "bumpmap:", 8))
        {
            bonus.bumpmap = ft_load_texture(s, option[i]);
            bonus.id[i] = 3;
        }
        else if (!ft_strncmp(option[i], "normal-disruption"
                    , ft_strlen(option[i]) + 1))
            bonus.id[i] = 1;
        else
            ft_error_handler(BAD_BONUS);
    }
    return (bonus);
}

t_bonus         ft_cylinder_bonus(char **option)
{
    t_bonus     bonus;
    int         i;

    i = 0;
    bonus.id[0] = 0;
    while (option[++i])
    {
        if (!ft_strncmp(option[i], "rainbow", ft_strlen(option[i]) + 1))
            bonus.id[i] = 5;
        else
            ft_error_handler(BAD_BONUS);
    }
    return (bonus);
}
