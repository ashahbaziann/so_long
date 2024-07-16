/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:11:51 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/16 16:44:38 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_construct(int argc, char **argv)
{
	int		fd;
	char	**map;

	map = NULL;
	if (argc != 2 || !valid_argv(argv[1], ".ber"))
		error("Wrong arguments!\n", NULL);
	fd = open(argv[1], O_RDONLY);
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

char	*check_line(char **new_line, char **line)
{
	*new_line = another_strtrim((*line), "\n");
	if (!(*new_line))
		line_free((*new_line), (*line));
	double_new_line((*new_line));
	return ((*new_line));
}

char	*get_the_line(int fd)
{
	char	*tmp;
	char	*line;
	char	*check;

	tmp = NULL;
	line = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		check = ft_strtrim(tmp, " \n\t\v");
		if (!check)
		{
			line_free(tmp, check);
			error("Validation failed!\n", line);
		}
		line = ft_strjoin(line, check);
		line_free(tmp, check);
		if (!line)
			error("Validation failed!\n", line);
	}
	line_free(tmp, NULL);
	return (line);
}

char	**read_map(int fd)
{
	char	*line;
	char	*new;
	char	**map;

	line = NULL;
	new = NULL;
	map = NULL;
	line = get_the_line(fd);
	if (!line || line_is_empty(line))
		error ("Validation failed!\n", line);
	new = check_line(&new, &line);
	if (!new)
		line_free(line, new);
	line_free(line, NULL);
	map = split(new, '\n');
	if (!map)
	{
		line_free(line, new);
		clean(NULL, map, "Validation failed!\n");
	}
	line_free(new, NULL);
	return (map);
}
