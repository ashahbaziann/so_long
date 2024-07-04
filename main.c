#include "so_long.h"

void	init_point(t_point *point)
{
	point -> x = 0;
	point -> y = 0;
}
void	init_game(t_game **game,char **map)
{
	(*game) = (t_game *)malloc(sizeof(t_game));
	if (!(*game))
		clean(game, map, "Invalid game!");
	(*game) -> map = map;
	(*game) -> coins = 0;
	(*game) -> exit = 0;
	(*game) -> player = 0;
	init_point(&((*game) -> curr));
}
int main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	game = NULL;
	map = map_construct(argc, argv);
	are_walls_surrounding(map);
	init_game(&game, map);
	printf("%d\n",(game -> curr).y);
	is_map_playable(&game);
	return (0);
}

