/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:10:39 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/05 16:43:15 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_point(t_point *point)
{
	point -> x = 0;
	point -> y = 0;
}

void	init_game(t_game **game, char **map)
{
	(*game) = (t_game *)malloc(sizeof(t_game));
	if (!(*game))
		clean((*game), NULL, "Invalid game!");
	(*game)-> map = map;
	(*game)-> coins = 0;
	(*game)-> exit = 0;
	(*game)-> player = 0;
	(*game)-> mlx = NULL;
	(*game)-> mlx_win = NULL;
	(*game)-> player_loc = &((*game)-> player);
	(*game)-> coins_loc = &((*game)-> coins);
	(*game)-> exit_loc = &((*game)-> exit);
	(*game)-> ground_loc = &((*game)-> ground);
	(*game)-> wall_loc = &((*game)-> wall);
	(*game)-> width = width((*game)-> map);
	(*game)-> height = height((*game)-> map);
	init_point(&((*game)-> curr));
}
