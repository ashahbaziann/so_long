/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:11:51 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/08 19:15:47 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		error("File can't be read!\n", line);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		line = ft_strjoin(line, tmp);
		free(tmp);
		if (!line)
			error("Line couldn't be joined\n", line);
	}
	map = split(line, '\n');
	free(tmp);
	free(line);
	return (map);
}

char**	map_construct(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2 || !valid_argv(argv[1], ".ber"))
		error("Wrong Input!\n", NULL);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		error("File can't be opened!\n", NULL);
	map = read_map(fd);
	// system("leaks so_long");
	return (map);
}
