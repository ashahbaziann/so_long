/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:09:11 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/09 13:56:19 by ashahbaz         ###   ########.fr       */
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
	mlx_loop(game -> mlx);
	return (0);
}

