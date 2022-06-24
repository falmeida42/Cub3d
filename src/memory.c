#include "cub3d.h"
#include <stdio.h>

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

void    delete_mapWorld(t_info *info)
{
    int i;

    i = 0;
    while (i < mapHeight)
        free(info->mapWorld[i++]);
    free(info->mapWorld);
}