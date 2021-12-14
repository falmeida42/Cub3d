#include "cub3d.h"

void    init_mlx(t_mlx  *mlx)
{
    mlx->mlx = mlx_init();
    mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "Cub3d");
    mlx_loop(mlx->mlx);
}