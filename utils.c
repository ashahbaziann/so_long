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
	//system("leaks a.out");
	exit(1);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	//system("leaks a.out");
}

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	width(char **map){
	int	i;

	//i = 0;
	// while (map[0][i])
	// 	i++;
	i = spec_strlen(map[0]);
	return (i);
}
