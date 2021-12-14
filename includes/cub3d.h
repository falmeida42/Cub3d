#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft.h"

typedef struct s_mlx
{
    void    *mlx;
    void    *mlx_win;
}t_mlx;


typedef struct s_game
{
    t_mlx   *mlx;
}t_game;

//MEMORY
void    init_game(t_game *game);
void    end_game(t_game *game);
//MEMORY

//MLX
void    init_mlx(t_mlx  *mlx);
//MLX
#endif