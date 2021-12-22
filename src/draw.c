#include "cub3d.h"

void  my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
   char  *dst;

   info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length, &info->endian);
   dst = info->addr + (y * info->line_length + x * (info->bits_per_pixel / 8));
   *(unsigned int *)dst = color;
}

void  drawSky(t_info *info, int x, int y)
{
   int   i;
   
   i = 0;
   while (i < y)
   {
      my_mlx_pixel_put(info, x, i, 0x00BFFF);
      i++;
   }
}

void  drawFloor(t_info *info, int x, int y)
{
   int   i;

   i = height;
   while (i > y)
   {
      my_mlx_pixel_put(info, x, i, 0x957A56);
      i--;
   }
}

void  verLine(t_info *info, int x, int y1, int y2, int color)
{
   int   i;

   i = y1;
   while (i <= y2)
   {
      my_mlx_pixel_put(info, x, i, color);
      i++;
   }
}