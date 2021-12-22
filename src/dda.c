#include "cub3d.h"

void    initial_side_dist_calc(t_dda *dda, double posX, double posY)
{
    if (dda->rayDirX < 0)
      {
         dda->stepX = -1;
         dda->sideDistX = (posX - dda->mapX) * dda->deltaDistX;
      }
      else
      {
         dda->stepX = 1;
         dda->sideDistX = (dda->mapX + 1.0 - posX) * dda->deltaDistX;
      }
      if (dda->rayDirY < 0)
      {
         dda->stepY = -1;
         dda->sideDistY = (posY - dda->mapY) * dda->deltaDistY;
      }
      else
      {
        dda->stepY = 1;
        dda->sideDistY = (dda->mapY + 1.0 - posY) * dda->deltaDistY;
      }
}

void  calc(t_info *info)
{
    int   x;
   x = 0;
   while (x < width)
   {
      info->dda.cameraX = 2 * x / (double)width - 1;
      info->dda.rayDirX = info->dirX + info->planeX * info->dda.cameraX;
      info->dda.rayDirY = info->dirY + info->planeY * info->dda.cameraX;
      info->dda.mapX = (int)info->posX;
      info->dda.mapY = (int)info->posY;
      info->dda.deltaDistX = fabs(1 / info->dda.rayDirX);
      info->dda.deltaDistY = fabs(1 / info->dda.rayDirY);      

      int   hit = 0;
      int   side;
      initial_side_dist_calc(&info->dda, info->posX, info->posY);
      while (hit == 0)
      {
         if (info->dda.sideDistX < info->dda.sideDistY)
         {
            info->dda.sideDistX += info->dda.deltaDistX;
            info->dda.mapX += info->dda.stepX;
            side = 0;
         }
         else
         {
            info->dda.sideDistY += info->dda.deltaDistY;
            info->dda.mapY += info->dda.stepY;
            side = 1;
         }
         if (info->mapWorld[info->dda.mapX][info->dda.mapY] > 0)
            hit = 1;
      }

      // SPLIT THAT //
      
      if (side == 0)
         info->dda.perpWallDist = (info->dda.mapX - info->posX + (1 - info->dda.stepX) / 2) / info->dda.rayDirX;
      else
         info->dda.perpWallDist = (info->dda.mapY - info->posY + (1 - info->dda.stepY) / 2) / info->dda.rayDirY;
      
      int   lineHeight = (int)(height / info->dda.perpWallDist);

      int   drawStart = -lineHeight / 2 + height / 2;
      if (drawStart < 0)
         drawStart = 0;
      int   drawEnd = lineHeight / 2 + height / 2;
      if (drawEnd >= height)
         drawEnd = height - 1;
      
      int   color;
      if (info->mapWorld[info->dda.mapY][info->dda.mapX] == 1)
         color = 0xFF0000;
      else if (info->mapWorld[info->dda.mapY][info->dda.mapX] == 2)
         color = 0x00FF00;
      else if (info->mapWorld[info->dda.mapY][info->dda.mapX] == 3)
         color = 0x0000FF;
      else if (info->mapWorld[info->dda.mapY][info->dda.mapX] == 4)
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