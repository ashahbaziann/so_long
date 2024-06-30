#ifndef SO_LONG_H
# define SO_LONG_H

#  include "gnl/get_next_line.h"
#  include <mlx.h>
#  include <unistd.h>
#  include <stdlib.h>
#  include <stdio.h>
#  include <fcntl.h>
#  include <string.h>

typedef struct s_point
{
	int	x;
	int	y;
} t_point;

typedef struct s_game
{
	t_point	curr;
	char	**map;
	int		player;
	int		height;
	int		width;
	int		coins;
	int		exit;
} t_game;


void	init_point(t_point *point);
void	init_game(t_game **game,char **map);


void	are_horizontal_walls_valid(char **map, int h_height);
void	are_vertical_walls_valid(char **map, int h_height, int w_width);
void	is_map_rectangular(char **map, int h_height, int w_width);
void	are_walls_surrounding(char **map);

void	is_map_playable(t_game **game);
void	is_map_playable_helper(t_game *game);

void	error(char *str1, char *str2);
void	map_free(char **map);
int		width(char **map);
int		height(char **map);

int		valid_argv(char *str1, char *str2);
char**	read_map(int fd);
char**	map_construct(int argc, char **argv);

size_t	count_words(char const *s, char c);
char	*word_mall(char const *s, size_t f_occ, size_t l_occ);
char	**arr_mall(char const*s, char **split, char c);
char	**split(char const *s, char c);

#endif
