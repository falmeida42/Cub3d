#include "cub3d.h"

int   keyPress(int key, t_info *info)
{
   if (key == W)
   {
      if (info->mapWorld[(int)(info->posX + info->dirY * info->moveSpeed)][(int)info->posY] == false)
         info->posX += info->dirX * info->moveSpeed;
      if (info->mapWorld[(int)info->posX][(int)(info->posY + info->dirY * info->moveSpeed)] == false)
         info->posY += info->dirY * info->moveSpeed;
   }
   if (key == S)
   {
      if (info->mapWorld[(int)(info->posX - info->dirX * info->moveSpeed)][(int)info->posY] == false)
         info->posX -= info->dirX * info->moveSpeed;
      if (info->mapWorld[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)] == false)
         info->posY -= info->dirY * info->moveSpeed;
   }
   if (key == D)
   {
      double oldDirX = info->dirX;
      info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
      info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
      double oldPlaneX = info->planeX;
      info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
      info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
   }
   if (key == A)
   {
      double oldDirX = info->dirX;
      info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
      info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
      double oldPlaneX = info->planeX;
      info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
      info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
   }
   if (key == ESC)
      exit(0);
   return (0);
}