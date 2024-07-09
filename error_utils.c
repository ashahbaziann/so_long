/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:11:29 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/09 13:27:19 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str1, char *str2)
{
	while (*str1)
	{
		write(2, str1, 1);
		str1++;
	}
	if (str2)
		free(str2);
	str2 = NULL;
	system("leaks so_long");
	exit(1);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	if (map[i])
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map[i]);
		map[i] = NULL;
		free(map);
		map = NULL;
	}
	// system("leaks so_long");
}

void	game_free(t_game *game)
{
	map_free(game->map);
	if (game -> mlx_win)
	{
		mlx_destroy_window(game -> mlx, game -> mlx_win);
		// free(game -> mlx_win);
	}
	if (game)
	{
		free(game);
		game = NULL;
	}
	// system("leaks so_long");
}

void	clean(t_game *game, char **copy, char *str)
{
	if (copy)
		map_free(copy);
	if (game)
		game_free(game);
	copy = NULL;
	game = NULL;
	error(str, NULL);
}
