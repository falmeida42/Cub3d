#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <math.h>
# include <../mlx_linux/mlx.h>
# include "libft.h"
# define mapWidth 24
# define mapHeight 24
# define width 640
# define height 480
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef struct s_dda
{
    double cameraX;
    double rayDirX;
    double rayDirY;
    int   mapX;
    int   mapY;
    double   sideDistX;
    double   sideDistY;
    double   deltaDistX;
    double   deltaDistY;
    double   perpWallDist;
    int   stepX;
    int   stepY;
}   t_dda;

typedef struct s_info
{
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    double  moveSpeed;
    double  rotSpeed;

    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     **mapWorld;
    t_dda   dda;
}   t_info;

//DDA
void  calc(t_info *info);
//DDA

//DRAW
void  my_mlx_pixel_put(t_info *info, int x, int y, int color);
void  drawSky(t_info *info, int x, int y);
void  drawFloor(t_info *info, int x, int y);
void  verLine(t_info *info, int x, int y1, int y2, int color);
//DRAW

//MOVIMENTS
int   keyPress(int key, t_info *info);
//MOVIMENTS

//MEMORY
void  create_mapWorld(t_info *info);
void    delete_mapWorld(t_info *info);
//MEMORY

#endif