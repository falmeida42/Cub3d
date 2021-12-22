#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# define mapWidth 24
# define mapHeight 24
# define width 640
# define height 480
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53

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
}   t_info;

#endif