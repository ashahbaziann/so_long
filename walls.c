/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:12:05 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/11 20:36:33 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	are_horizontal_walls_valid(t_game *game)
{
	int	j;

	j = 0;
	while (game -> map[0][j])
	{
		if (game -> map[0][j] != '1')
			clean(game, NULL, "Missing walls!\n");
		j++;
	}
	j = 0;
	while (game -> map[(game -> height) - 1][j])
	{
		if (game -> map[(game -> height) - 1][j] != '1')
			clean(game, NULL, "Missing walls!\n");
		j++;
	}
}

void	are_vertical_walls_valid(t_game *game)
{
	int	i;

	i = 0;
	while (i < game -> height)
	{
		if (game -> map[i][0] != '1')
			clean(game, NULL, "Missing walls!\n");
		i++;
	}
	while (i - 1 > 0)
	{
		if (game -> map[i - 1][(game -> width) - 1] != '1')
			clean(game, NULL, "Missing walls!\n");
		i--;
	}
}

void	is_map_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game -> height)
	{
		j = 0;
		while (j < game -> width)
		{
			if (!(game -> map[i][j]))
				clean(game, NULL, "Map isn't in the rectangular form!\n");
			j++;
		}
		i++;
	}
}

void	are_walls_surrounding(t_game *game)
{
	is_map_rectangular(game);
	are_horizontal_walls_valid(game);
	are_vertical_walls_valid(game);
}
