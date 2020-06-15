#include "miniRT.h"

void	ft_image_header(t_image_header *bih, t_scene scene)
{
    bih->size_header = sizeof(t_image_header);
    bih->width = scene.x;
    bih->height = scene.y;
    bih->planes = 1;
    bih->bit_count = 32;
    bih->compression = 0;
    bih->image_size = 0;
    bih->ppm_x = 0;
    bih->ppm_y = 0;
    bih->clr_used = 0;
    bih->clr_important = 0;
}

void    ft_file_header(t_file_header *bfh, int file_size)
{
    ft_memcpy(&bfh->bitmap_type, "BM", 2);
    bfh->file_size[0] = (unsigned char)(file_size >> 24);
    bfh->file_size[3] = (unsigned char)(file_size >> 16);
    bfh->file_size[2] = (unsigned char)(file_size >> 8);
    bfh->file_size[1] = (unsigned char)file_size;
    bfh->reserved1 = 0;
    bfh->reserved2 = 0;
    bfh->offset_bits = 54;
    bfh->reserved3 = 0;

}

void    ft_convert_buffer_to_bmp(int fd, t_scene scene)
{
    t_file_header       bfh;
    t_image_header      bih;
    int                 image_size;
    int                 file_size;
    int                 i;

    image_size = scene.x * scene.y;
    i = image_size * 4;
    file_size = 54 + (4 * image_size);
    ft_file_header(&bfh, file_size);
    ft_image_header(&bih, scene);
    write(fd, &bfh, sizeof(bfh));
    write(fd, &bih, sizeof(bih));
    while (i > 0)
    {
        write(fd, scene.img.addr + i, scene.img.len);
        i -= scene.img.len;
    }
}

void    ft_scene_to_bmp(t_scene scene)
{
    int fd;

    scene.i_cam = 0;
    scene.window.mlx_ptr = mlx_init();
    scene.img.id = mlx_new_image(scene.window.mlx_ptr, scene.x, scene.y);
    scene.img.addr = mlx_get_data_addr(scene.img.id, &scene.img.bitpixl,
            &scene.img.len, &scene.img.end);
    ft_printf("converting scene to bmp...\n");
    ft_render_scene(&scene, scene.i_cam);
    if ((fd = open("output_scenes/output.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0744)) == -1)
        ft_error_handler(4);
    ft_convert_buffer_to_bmp(fd, scene);
    close (fd);
    ft_printf("saved!\n");
}
