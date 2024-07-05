/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:12:05 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/05 16:40:53 by ashahbaz         ###   ########.fr       */
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
			clean(game, NULL, "Missing walls!");
		j++;
	}
	while (game -> map[(game -> height) - 1][j])
	{
		if (game -> map[(game -> height) - 1][j] != '1')
			clean(game, NULL, "Missing walls!");
		j--;
	}
}

void	are_vertical_walls_valid(t_game *game)
{
	int	i;

	i = 0;
	while (i < game -> height)
	{
		if (game -> map[i][0] != '1')
			clean(game, NULL, "Missing walls!");
		i++;
	}
	while (i - 1 > 0)
	{
		if (game -> map[i - 1][(game -> width) - 1] != '1')
			clean(game, NULL, "Missing walls!");
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
				clean(game, NULL, "Map isn't in the rectangular form!");
			j++;
		}
		i++;
	}
}

// int	is_white_spc(char c)
// {
// 	if (c == ' ' || c == '\t')
// 		return (1);
// 	return (0);
// }

// int	spec_strlen(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (is_white_spc(str[i]))
// 		{
// 			while (is_white_spc(str[i]))
// 				i++;
// 			if (str[i] == '\0')
// 				return (count);
// 			else
// 				return (0);
// 		}
// 		count++;
// 		i++;
// 	}
// 	return (count);
// }

// pec_strlen(char *str, int width)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (!((str[i] == ' ' || str[i] == '\t') && i >= width))
// 		{
// 			if (str[i])
// 				count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }
// void	is_map_rectangular(char **map, int h_height, int w_width)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < h_height)
// 	{
// 		printf("spec = %d\n",spec_strlen(map[i]));

// 		printf("width = %d\n",w_width);
// 		if (spec_strlen(map[i]) != w_width)
// 			clean(NULL, map, "Map isn't in the rectangular form!");
// 		i++;
// 	}
// }
void	are_walls_surrounding(t_game *game)
{
	is_map_rectangular(game);
	are_horizontal_walls_valid(game);
	are_vertical_walls_valid(game);
}
