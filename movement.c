/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:12:59 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/05 20:13:20 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void clear_current_position(t_game *game)
{
    game -> map[game->curr.y][game->curr.x] = '0';
}

void redraw_map(t_game *game)
{
    create_map(game);
}

int	check_direction( char value)
{
	if (value == '1')
			return (1);
			return(0);
	// else if (value == 'C')
	// {
	// 	if (game -> coins == 0)
	// 		exit(0);
	// 	else
	// 		game -> coins--;
	// }
	// if (value == 'E')
}
void move_player(t_game *game, int dx, int dy, char direction)
{
	if (direction == 'U')
		if (check_direction( game ->map[game ->curr.y - 1][game ->curr.x]) == 1)
			return;
	if (direction == 'D')
		if (check_direction(game, game ->map[game ->curr.y + 1][game ->curr.x]) == 2)
	if (direction == 'R')
		if(check_direction(game, game ->map[game ->curr.y][game ->curr.x + 1]) == 3)
	if (direction == 'L')
		if(check_direction(game, game ->map[game ->curr.y][game ->curr.x - 1]) == 3)


	clear_current_position(game);
    game -> curr.x += dx;
    game -> curr.y += dy;
	game->map[game->curr.y][game->curr.x] = 'P';

	redraw_map(game);
}

int	handle_movement(int keycode, t_game *game)
{
	//printf("Key pressed: %d\n", keycode);
	printf ("%d\n",game -> coins);
	if (keycode == 53)
    {
        mlx_destroy_window(game -> mlx, game -> mlx_win);
        exit(0);
    }
    else if (keycode == 123)
        move_player(game, -1, 0, 'L');
    else if (keycode == 126)
        move_player(game, 0, -1, 'U');
    else if (keycode == 124)
        move_player(game, 1, 0, 'R');
    else if (keycode == 125)
        move_player(game, 0, 1, 'D');
    return 0;
}



int	handle_close(t_game *game)
{
    mlx_destroy_window(game -> mlx, game -> mlx_win);
    free(game -> mlx);
    return 0;
}
