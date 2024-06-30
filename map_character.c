#include "so_long.h"

void	is_map_playable(t_game **game)
{
	is_map_playable_helper(*game);
	if (!((*game) -> player == 1 && (*game) -> exit == 1 && (*game) -> coins >= 1))
	{
		map_free((*game) -> map);
		error("Not enough values on the map!", NULL);
	}
}

void	is_map_playable_helper(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	game -> height = height(game -> map);
	while (i < (game -> height) - 1)
	{
		j = 1;
		while (game -> map[i][j] != '1')
		{
			if (game -> map[i][j] == 'P')
				(game -> player)++;
			else if (game -> map [i][j] == 'C')
				(game -> coins)++;
			else if (game -> map [i][j] == 'E')
				(game -> exit)++;
			else if (game -> map [i][j] != '0' && game -> map [i][j] != '1')
				{
					map_free(game -> map );
					error("Not valid input values!", NULL);
				}
			j++;
		}
		i++;
	}
}
