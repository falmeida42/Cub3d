#include "cub3d.h"

void    init_game(t_game *game)
{
    game->data = malloc(sizeof(t_data));
}

void    end_game(t_game *game)
{
    free(game->data);
    free(game);
}