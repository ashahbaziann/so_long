#include "so_long.h"

void	are_horizontal_walls_valid(char **map, int h_height)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
		{
			map_free(map);
			error("Missing walls!", NULL);
		}
		j++;
	}
	while (map[h_height - 1][j - 1])
	{
		if (map[h_height - 1][j - 1] != '1')
		{
			map_free(map);
			error("Missing walls!", NULL);
		}
		j--;
	}
}

void	are_vertical_walls_valid(char **map, int h_height, int w_width)
{
	int	i;

	i = 0;
	while (i < h_height)
	{
		if (map[i][0] != '1')
		{
			map_free(map);
			error("Missing walls!", NULL);
		}
		i++;
	}
	while (i - 1 > 0)
	{
		if (map[i - 1][w_width - 1] != '1')
		{
			map_free(map);
			error("Missing walls!", NULL);
		}
		i--;
	}
}

void	is_map_rectangular(char **map, int h_height, int w_width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < h_height)
	{
		j = 0;
		while (j < w_width)
		{
			if (!map[i][j])
			{
				map_free(map);
				error("Map isn't in the rectangular form!", NULL);
			}
		j++;
		}
		i++;
	}
}
void	are_walls_surrounding(char **map)
{
	int w_width;
	int	h_height;

	w_width = width(map);
	h_height = height(map);
	is_map_rectangular(map, h_height, w_width);
	are_horizontal_walls_valid(map, h_height);
	are_vertical_walls_valid(map, h_height, w_width);
}

