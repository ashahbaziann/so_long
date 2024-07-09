/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:10:25 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/09 13:58:41 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game -> mlx = mlx_init();
	if (!game -> mlx)
		clean(game, NULL, "Couldn't create window!\n");
	game -> mlx_win = mlx_new_window(game -> mlx, game -> width * SPRITE,
			game -> height * SPRITE, "so_long");
	if (!game -> mlx_win)
		clean(game, NULL, "Couldn't create window!\n");
}

void	init_images(t_game *game)
{
	t_point	i;

	game -> player_loc = mlx_xpm_file_to_image(game -> mlx,
			"xpms/player.xpm", &i.x, &i.y);
	game -> coins_loc = mlx_xpm_file_to_image(game -> mlx,
			"xpms/coin.xpm", &i.x, &i.y);
	game -> exit_loc = mlx_xpm_file_to_image(game -> mlx,
			"xpms/exit.xpm", &i.x, &i.y);
	game -> wall_loc = mlx_xpm_file_to_image(game -> mlx,
			"xpms/wall.xpm", &i.x, &i.y);
	game -> ground_loc = mlx_xpm_file_to_image(game -> mlx,
			"xpms/grass.xpm", &i.x, &i.y);
}

void	create_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game -> height)
	{
		j = 0;
		while (game -> map[i][j])
		{
			put_image(game, i, j, game -> map[i][j]);
			j++;
		}
		i++;
	}
}

void	put_image(t_game *game, int i, int j, char val)
{
	if (val == '0')
		put_image_helper(game, game -> ground_loc, i, j);
	else if (val == '1')
		put_image_helper(game, game -> wall_loc, i, j);
	else if (val == 'E')
		put_image_helper(game, game -> exit_loc, i, j);
	else if (val == 'C')
		put_image_helper(game, game -> coins_loc, i, j);
	else if (val == 'P')
		put_image_helper(game, game -> player_loc, i, j);
}

void	put_image_helper(t_game *game, void *val, int i, int j)
{
	mlx_put_image_to_window(game -> mlx, game -> mlx_win,
		val, j * SPRITE, i * SPRITE);
}
