#include "cub3d.h"

int   worldMap[mapWidth][mapHeight] = 
{
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void  drawSky(t_info *info, int x, int y)
{
   int   i;
   
   i = 0;
   while (i < y)
   {
      mlx_pixel_put(info->mlx, info->win, x, i, 0x00BFFF);
      i++;
   }
}

void  drawFloor(t_info *info, int x, int y)
{
   int   i;

   i = height;
   while (i > y)
   {
      mlx_pixel_put(info->mlx, info->win, x, i, 0x957A56);
      i--;
   }
}

void  verLine(t_info *info, int x, int y1, int y2, int color)
{
   int   i;

   i = y1;
   while (i <= y2)
   {
      mlx_pixel_put(info->mlx, info->win, x, i, color);
      i++;
   }
}

void  calc(t_info *info)
{
   int   x;
   x = 0;
   while (x < width)
   {
      double cameraX = 2 * x / (double)width - 1;
      double rayDirX = info->dirX + info->planeX * cameraX;
      double rayDirY = info->dirY + info->planeY * cameraX;

      int   mapX = (int)info->posX;
      int   mapY = (int)info->posY;

      double   sideDistX;
      double   sideDistY;

      double   deltaDistX = fabs(1 / rayDirX);
      double   deltaDistY = fabs(1 / rayDirY);
      double   perpWallDist;

      int   stepX;
      int   stepY;

      int   hit = 0;
      int   side;

      if (rayDirX < 0)
      {
         stepX = -1;
         sideDistX = (info->posX - mapX) * deltaDistX;
      }
      else
      {
         stepX = 1;
         sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
         stepY = -1;
         sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
      }

      while (hit == 0)
      {
         if (sideDistX < sideDistY)
         {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
         }
         else
         {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
         }
         if (worldMap[mapX][mapY] > 0)
            hit = 1;
      }

      if (side == 0)
         perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
      else
         perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
      
      int   lineHeight = (int)(height / perpWallDist);

      int   drawStart = -lineHeight / 2 + height / 2;
      if (drawStart < 0)
         drawStart = 0;
      int   drawEnd = lineHeight / 2 + height / 2;
      if (drawEnd >= height)
         drawEnd = height - 1;
      
      int   color;
      if (worldMap[mapY][mapX] == 1)
         color = 0xFF0000;
      else if (worldMap[mapY][mapX] == 2)
         color = 0x00FF00;
      else if (worldMap[mapY][mapX] == 3)
         color = 0x0000FF;
      else if (worldMap[mapY][mapX] == 4)
         color = 0xFFFFFF;
      else
         color = 0xFFFF00;
      
      if (side == 1)
         color = color / 2;

      drawSky(info, x, drawStart);
      verLine(info, x, drawStart, drawEnd, color);
      drawFloor(info, x, drawEnd);
      x++;
   }
}

int   main_loop(t_info *info)
{
   calc(info);
   return (0);
}

int main(void)
{
   t_info   info;
   info.mlx = mlx_init();

   info.posX = 12;
   info.posY = 5;
   info.dirX = -1;
   info.dirY = 0;
   info.planeX = 0;
   info.planeY = 0.66;
   info.moveSpeed = 0.05;
   info.rotSpeed = 0.05;

   info.win = mlx_new_window(info.mlx, width, height, "Cub3d");

   mlx_loop_hook(info.mlx, &main_loop, &info);
   mlx_loop(info.mlx);
}