#include  <stdio.h>
#include "mlx.h"


typedef struct	s_window {
    void	*mlx_ptr;
    void	*win_ptr;
    int		button;
}		t_window;

typedef struct	s_image{
    void        *id;
    char        *addr;
    int         len;
    int         bitpixl;
    int         end;
}               t_image;

typedef struct s_all{
    t_window    window;
    t_image     img;
}               t_all;

//Pinta un cuadrado en el centro de 50 x 50
void    paint_scene(t_all *a, char id)
{
    int x = 225;
    int y = 225;

    while (x < 275)
    {
        while (y < 275)
        {
            *(unsigned int *)(a->img.addr + (y * a->img.len + x * (a->img.bitpixl / 8))) = 0xEF0000FF;
            y++;
        }
        y = 225;
        x++;
    }
    printf("color: %#x\n", *(unsigned int *)(a->img.addr + (230 * a->img.len + 230 * (a->img.bitpixl / 8))));
}

int     ft_handle_keyboard(int key, t_all *a)
{
    char id;

    id = 0;
    printf("%d\n", key);
    if (key == 123)
    {
        paint_scene(a, id);
        mlx_clear_window(a->window.mlx_ptr, a->window.win_ptr);
        mlx_put_image_to_window(a->window.mlx_ptr, a->window.win_ptr, a->img.id, 0, 0);
    }
    return (0);
}

int main()
{
    t_all     a;
    //Inicializamos todo
    a.window.mlx_ptr = mlx_init();
    a.window.win_ptr = mlx_new_window(a.window.mlx_ptr, 500, 500, "prueba colores");
    a.img.id = mlx_new_image(a.window.mlx_ptr, 500, 500);
    a.img.addr = mlx_get_data_addr(a.img.id, &a.img.bitpixl,&a.img.len,&a.img.end);
    //Declaramos las funciones
    mlx_key_hook(a.window.win_ptr, ft_handle_keyboard, &a);
    mlx_loop(a.window.mlx_ptr);
    return (0);
}
