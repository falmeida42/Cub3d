#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft.h"

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     test;
}t_data;


typedef struct s_game
{
    t_data   *data;
}t_game;

//MEMORY
void    init_game(t_game *game);
void    end_game(t_game *game);
//MEMORY

//MLX
void    build_square(t_data *data, int x, int y, int color);
void    init_mlx(t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
//MLX
#endif