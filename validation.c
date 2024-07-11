/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:11:51 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/11 18:53:32 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_construct(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2 || !valid_argv(argv[1], ".ber"))
		error("Wrong arguments!\n", NULL);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		error("File can't be opened!\n", NULL);
	map = read_map(fd);
	return (map);
}

int	valid_argv(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1)
		return (0);
	if (ft_strlen(str1) <= 4)
		return (0);
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

void	double_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			error("Validation failed!\n", line);
		i++;
	}
}

char	*check_line(char **new_line, char **line)
{
	*new_line = another_strtrim((*line), "\n");
	if (!(*new_line))
		line_free((*new_line), (*line));
	double_new_line((*new_line));
	return ((*new_line));
}

char	**read_map(int fd)
{
	char	*line;
	char	*tmp;
	char	*check;
	char	*new;
	char	**map;

	line = NULL;
	new = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		check = ft_strtrim(tmp, " \n\t\v");
		if (!check)
			line_free(tmp, check);
		line = ft_strjoin(line, check);
		line_free(tmp, check);
		if (!line)
			error("Validation failed!\n", line);
	}
	new = check_line(&new, &line);
	map = split(line, '\n');
	line_free(new, line);
	return (map);
}
