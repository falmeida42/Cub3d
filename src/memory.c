#include "cub3d.h"

void    init_game(t_game *game)
{
    game = malloc(sizeof(t_game));
    game->mlx = malloc(sizeof(t_mlx));
}

void    end_game(t_game *game)
{
    free(game->mlx);
    free(game);
}