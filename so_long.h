/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:12:46 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/05 20:10:55 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 50
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	t_point	curr;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		player;
	int		height;
	int		width;
	int		coins;
	int		exit;
	int		wall;
	int		ground;
	void	*player_loc;
	void	*coins_loc;
	void	*exit_loc;
	void	*ground_loc;
	void	*wall_loc;
}	t_game;

int	check_direction(char value);
void clear_current_position(t_game *game);
void redraw_map(t_game *game);
void move_player(t_game *game, int dx, int dy, char direction);
int	handle_movement(int keycode, t_game *game);
int	handle_close(t_game *game);

void	init_window(t_game *game);
void	init_images(t_game *game);
void	create_map(t_game *game);
void	put_image(t_game *game, int i, int j, char val);
void	put_image_helper(t_game *game, void *val, int i, int j);

char	*ft_strcpy(char *dest, char *src);
int		ft_strchr(char *s, int c);

void	init_point(t_point *point);
void	init_game(t_game **game, char **map);

void	are_horizontal_walls_valid(t_game *game);
void	are_vertical_walls_valid(t_game *game);
void	is_map_rectangular(t_game *game);
void	are_walls_surrounding(t_game *game);

char	**copy_matrix(t_game *game);
void	clean(t_game *game, char **copy, char *str);
void	flood_fill(char **copy, t_point current, int width, int height);
void	check_map(char **copy, t_game *game);
void	check_all_routes(t_game *game);

void	player_location(t_game *game, int i, int j);
void	is_map_playable(t_game **game);
void	is_map_playable_helper(t_game *game);

void	error(char *str1, char *str2);
void	map_free(char **map);
void	game_free(t_game *game);
int		width(char **map);
int		height(char **map);

int		valid_argv(char *str1, char *str2);
char	**read_map(int fd);
char	**map_construct(int argc, char **argv);

size_t	count_words(char const *s, char c);
char	*word_mall(char const *s, size_t f_occ, size_t l_occ);
char	**arr_mall(char const*s, char **split, char c);
char	**split(char const *s, char c);

#endif
