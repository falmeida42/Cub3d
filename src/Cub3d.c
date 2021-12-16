#include "cub3d.h"

int main(void)
{
   t_game   *game;

   game = malloc(sizeof(t_game));
   init_game(game);
   init_mlx(game->data);
   return (0);
}