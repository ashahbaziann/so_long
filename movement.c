/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:12:59 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/11 18:50:56 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_current_position(t_game *game)
{
	game -> map[game ->curr.y][game ->curr.x] = '0';
	put_image(game, game->curr.y, game->curr.x, '0');
}

void	the_end(t_game *game)
{
	mlx_destroy_image(game -> mlx, game -> wall_loc);
	mlx_destroy_image(game -> mlx, game -> exit_loc);
	mlx_destroy_image(game -> mlx, game -> ground_loc);
	mlx_destroy_image(game -> mlx, game -> player_loc);
	mlx_destroy_image(game -> mlx, game -> coins_loc);
	game_free(game);
	game = NULL;
}

void	move_player(t_game *game, int dx, int dy)
{
	if (game -> map[(game ->curr.y) + dy][(game ->curr.x) + dx] == '1')
		return ;
	if (game -> map[(game ->curr.y) + dy][(game ->curr.x) + dx] == 'C')
		game -> coins--;
	if (game -> map[(game ->curr.y) + dy][(game ->curr.x) + dx] == 'E')
	{
		if (game -> coins <= 0)
		{
			game -> steps++;
			clear_current_position(game);
			ft_putnbr(game -> steps);
			write (1, "\n", 1);
			the_end(game);
			write (1, "You Win!\n", 9);
			exit(0);
		}
		else
			return ;
	}
	clear_current_position(game);
	game -> curr.x += dx;
	game -> curr.y += dy;
	put_image(game, game->curr.y, game->curr.x, 'P');
	game -> steps++;
}

int	handle_movement(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		the_end(game);
		game = NULL;
		exit(0);
	}
	else if (keycode == 123)
		move_player(game, -1, 0);
	else if (keycode == 126)
		move_player(game, 0, -1);
	else if (keycode == 124)
		move_player(game, 1, 0);
	else if (keycode == 125)
		move_player(game, 0, 1);
	ft_putnbr(game -> steps);
	write (1, "\n", 1);
	return (0);
}

int	handle_close(t_game *game)
{
	the_end(game);
	game = NULL;
	exit(0);
	return (0);
}
