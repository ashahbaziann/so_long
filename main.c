/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:09:11 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/05 19:45:51 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	game = NULL;
	map = map_construct(argc, argv);
	init_game(&game, map);
	are_walls_surrounding(game);
	is_map_playable(&game);
	check_all_routes(game);
	init_window(game);
	init_images(game);
	create_map(game);
	mlx_hook(game -> mlx_win, 2, 0, handle_movement, game);
	mlx_hook(game -> mlx_win, 17, 0, handle_close, game);
	printf ("%d\n",game -> coins);
	mlx_loop(game -> mlx);
	system("leaks so_long");
	int i = 0;
	int j = 0;
	char **copy = copy_matrix(game);
	while (i < game -> height)
	{
		j = 0;
		while (j < game  -> width)
		{
			printf("%c ", copy[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}

