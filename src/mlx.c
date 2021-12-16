#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    init_mlx(t_data *data)
{
   data->mlx = mlx_init();
   data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Cub3d");
   data->img = mlx_new_image(data->mlx, 1920, 1080);
   data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
   my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
   mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
   mlx_loop(data->mlx);
}
