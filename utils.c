/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:11:29 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/05 18:09:53 by ashahbaz         ###   ########.fr       */
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
		free(map);
		map = NULL;
	}
	system("leaks so_long");
}

void	game_free(t_game *game)
{
	map_free(game -> map);
	if (game -> mlx)
	{
		mlx_destroy_window(game -> mlx, game -> mlx_win);
		free(game -> mlx);
	}
	if (game -> mlx_win)
	{
		mlx_destroy_window(game -> mlx, game -> mlx_win);
		free(game -> mlx_win);
	}
	if (game)
	{
		free(game);
		game = NULL;
	}
	system("leaks so_long");
}

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}
