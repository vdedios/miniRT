#include "miniRT.h"

void            ft_file_header(t_scene scene, int fd)
{
    int				filesize;
    int                         padding;
    static unsigned char	fileheader[] = {
        0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
    };

    padding = (4 - (scene.x * 3) % 4) % 4;
    filesize = 54 + (3 * scene.x + padding) * scene.y;
    fileheader[0] = (unsigned char)('B');
    fileheader[1] = (unsigned char)('M');
    fileheader[2] = (unsigned char)(filesize);
    fileheader[3] = (unsigned char)(filesize >> 8);
    fileheader[4] = (unsigned char)(filesize >> 16);
    fileheader[5] = (unsigned char)(filesize >> 24);
    fileheader[10] = (unsigned char)(54);
    write(fd, fileheader, 14);
}

void	        ft_image_header(t_scene s, int fd)
{	
    static unsigned char	infoheader[] = {
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
    };

    infoheader[0] = (unsigned char)(40);
    infoheader[4] = (unsigned char)(s.x);
    infoheader[5] = (unsigned char)(s.x >> 8);
    infoheader[6] = (unsigned char)(s.x >> 16);
    infoheader[7] = (unsigned char)(s.x >> 24);
    infoheader[8] = (unsigned char)(s.y);
    infoheader[9] = (unsigned char)(s.y >> 8);
    infoheader[10] = (unsigned char)(s.y >> 16);
    infoheader[11] = (unsigned char)(s.y >> 24);
    infoheader[12] = (unsigned char)(1);
    infoheader[14] = (unsigned char)(24);
    write(fd, infoheader, 40);
}

void           ft_convert_buffer_to_bmp(int fd, t_scene scene)
{
    int                         i;
    int                         padding;
    static unsigned char        zero[3] = { 0, 0, 0};

    ft_file_header(scene, fd);
    ft_image_header(scene, fd);
    padding = (4 - (scene.x * 3) % 4) % 4;
    i = scene.x * scene.y;
    while (i > 0)
    {
        write(fd, scene.img.addr + i, 3);
        if (!(i % scene.x) && padding > 0)
            write(fd, &zero, padding);
        i--;
    }
}

void            ft_scene_to_bmp(t_scene scene)
{
    int fd;

    scene.i_cam = 0;
    scene.img.id = mlx_new_image(scene.window.mlx_ptr, scene.x, scene.y);
    scene.img.addr = (int *)mlx_get_data_addr(scene.img.id, &scene.img.bitpixl,
            &scene.img.len, &scene.img.end);
    ft_printf("converting scene to bmp...\n");
    ft_render_scene(&scene);
    if ((fd = open("output_bmp/output.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0744)) == -1)
        ft_error_handler(4);
    ft_convert_buffer_to_bmp(fd, scene);
    close (fd);
    ft_printf("saved!\n");
}
