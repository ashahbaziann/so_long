#include "so_long.h"

int	valid_argv(char *str1, char *str2)
{
	int	i;
	i = 0;

	while (*str1)
		str1++;
	while (*str2)
		str2++;
	while (i < 4 && *str1 == *str2)
		{
			i++;
			str1--;
			str2--;
		}
	if (i == 4)
		return (1);
	return (0);
}

char**	read_map(int fd)
{
	char	*line;
	char	*tmp;
	char	**map;

	line = get_next_line(fd);
	if (!line)
		error("File can't be read!", line);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		line = ft_strjoin(line, tmp);
		free(tmp);
		if (!line)
			error("Line couldn't be joined", line);
	}
	map = split(line, '\n');
	free(tmp);
	free(line);
	//system("leaks a.out");
	return (map);
}

char**	map_construct(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2 || !valid_argv(argv[1], ".ber"))
		error("Wrong Input!", NULL);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		error("File can't be opened!", NULL);
	map = read_map(fd);
	return (map);
}
