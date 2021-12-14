#include "cub3d.h"

int main(void)
{
   t_game   game;

   init_game(&game);
   init_mlx(game.mlx);
   end_game(&game);
   return (0);
}