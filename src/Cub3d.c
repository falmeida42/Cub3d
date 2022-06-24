#include "cub3d.h"

int   main_loop(t_info *info)
{
   calc(info);
   mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
   return (0);
}

void  init_variables(t_info *info)
{
   info->mlx = mlx_init();
   info->posX = 12;
   info->posY = 5;
   info->dirX = -1;
   info->dirY = 0;
   info->planeX = 0;
   info->planeY = 0.66;
   info->moveSpeed = 0.2;
   info->rotSpeed = 0.1;
}

int   main(void)
{
   t_info   info;

   printf("Initializing variables\n");
   init_variables(&info);
   printf("Variables initialized\n");
   printf("Creating mapWorld\n");
   create_mapWorld(&info);
   printf("MapWorld created\n");
   printf("Initializing Mlx\n");
   info.win = mlx_new_window(info.mlx, width, height, "Cub3d");
   info.img = mlx_new_image(info.mlx, width, height);
   info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
   printf("Mlx initialized\n");
   printf("Mlx Loop_hook\n");
   mlx_loop_hook(info.mlx, &main_loop, &info);
   printf("Mlx info.win\n");
   mlx_hook(info.win, 2, 1L << 0, &keyPress, &info);
   printf("Mlx info\n");
   mlx_loop(info.mlx);
   printf("End\n");
}