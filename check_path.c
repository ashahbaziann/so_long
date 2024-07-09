/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:09:51 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/08 19:18:56 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_matrix(t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * ((game -> height) + 1));
	if (!copy)
		clean(game, copy, "Allocation failed\n!");
	while (i < game -> height)
	{
		copy[i] = malloc(sizeof(char) * ((game -> width) + 1));
		if (!copy[i])
		{
			free(copy[i]);
			copy[i] = NULL;
			clean(game, copy, "Allocation failed!\n");
		}
		copy[i] = ft_strcpy(copy[i], game -> map[i]);
		i++;
	}
	copy[game->height] = NULL;
	return (copy);
}

void	flood_fill(char **copy, t_point current, int width, int height)
{
	if (current.x < 0 || current.y < 0
		|| current.x >= width || current.y >= height)
		return ;
	if (ft_strchr("CP", copy[current.y][current.x]))
		copy[current.y][current.x] = '0';
	if (copy[current.y][current.x] != '0')
		return ;
	copy[current.y][current.x] = 'F';
	flood_fill(copy, (t_point){current.x + 1, current.y}, width, height);
	flood_fill(copy, (t_point){current.x - 1, current.y}, width, height);
	flood_fill(copy, (t_point){current.x, current.y + 1}, width, height);
	flood_fill(copy, (t_point){current.x, current.y - 1}, width, height);
}

void	check_map(char **copy, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game -> height)
	{
		j = 0;
		while (j < game -> width)
		{
			if (!ft_strchr("10FE", copy[i][j]))
				clean(game, copy, "Wrong path!\n");
			j++;
		}
		i++;
	}
}

void	check_all_routes(t_game *game)
{
	char	**copy;

	copy = copy_matrix(game);
	flood_fill(copy, game -> curr, game -> width, game -> height);
	check_map(copy, game);
	map_free(copy);
	// system("leaks so_long");
}


