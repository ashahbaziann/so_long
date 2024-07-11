/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_character.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:11:00 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/11 17:39:47 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_playable(t_game **game)
{
	is_map_playable_helper(*game);
	if (!((*game)-> player == 1 && (*game)-> exit == 1
			&& (*game)-> coins >= 1))
		clean((*game), NULL, "Map isn't playable!\n");
}

void	player_location(t_game *game, int i, int j)
{
	game -> curr.x = i;
	game -> curr.y = j;
	(game -> player)++;
}

void	is_map_playable_helper(t_game *game)
{
	int		i;
	int		j;

	i = 1;
	while (i < (game -> height))
	{
		j = 0;
		while (game -> map[i][j])
		{
			if (game -> map[i][j] == 'P')
				player_location(game, j, i);
			else if (game -> map [i][j] == 'C')
				(game -> coins)++;
			else if (game -> map [i][j] == 'E')
				(game -> exit)++;
			else if (game -> map [i][j] == '0')
				(game -> ground)++;
			else if (game -> map [i][j] == '1')
				(game -> wall)++;
			else
				clean (game, NULL, "Not valid values!\n");
			j++;
		}
		i++;
	}
}
