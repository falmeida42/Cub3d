#include "cub3d.h"

int   main_loop(t_info *info)
{
   calc(info);
   mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
   return (0);
}

void  create_mapWorld(t_info *info)
{
   int   i;
   int   j;
   info->mapWorld = malloc(sizeof(int *) * mapHeight);
   
   i = 0;
   while (i < mapHeight)
   {
      info->mapWorld[i] = malloc(sizeof(int) * mapWidth);
      i++;
   }
   i = 0;
   while (i < mapHeight)
   {
      j = 0;
      while (j < mapWidth)
      {
         if (i == 0 || i == mapHeight - 1)
            info->mapWorld[i][j] = 1;
         else if (j == 0 || j == mapWidth - 1)
            info->mapWorld[i][j] = 1;
         else if (j == 10 && i == 15)
            info->mapWorld[i][j] = 2;
         else if (j == 12 && i == 17)
            info->mapWorld[i][j] = 3;
         else if (j == 5 && i == 4)
            info->mapWorld[i][j] = 4;
         else if (j == 13 && i == 9)
            info->mapWorld[i][j] = 2;
         else
            info->mapWorld[i][j] = 0;
         j++;
      }
      i++;
   }
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

   init_variables(&info);
   create_mapWorld(&info);
   info.win = mlx_new_window(info.mlx, width, height, "Cub3d");
   info.img = mlx_new_image(info.mlx, width, height);
   info.addr = mlx_get_data_addr(info.img, &info.bits_per_pixel, &info.line_length, &info.endian);
   mlx_loop_hook(info.mlx, &main_loop, &info);
   mlx_hook(info.win, 2, 1L << 0, &keyPress, &info);
   mlx_loop(info.mlx);
}