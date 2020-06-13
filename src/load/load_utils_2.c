#include "miniRT.h"

void    ft_check_system_resolution(t_scene *scene)
{
    int w;
    int h;

#if __APPLE__
    CGDirectDisplayID mainDisplayId = CGMainDisplayID();
    w = CGDisplayPixelsWide(mainDisplayId) - 100;
    h = CGDisplayPixelsHigh(mainDisplayId) - 100;
#else
    w = 1000;
    h = 1000;
#endif
    if (scene->x > w)
        scene->x = w;
    if (scene->y > h)
        scene->y = h;
}
