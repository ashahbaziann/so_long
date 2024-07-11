/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:06:30 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/11 17:07:26 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1);
	if (line_is_empty(s1))
		return (ft_strdup("\n"));
	else
	{
		while (i && ft_strchr(set, s1[i]))
			i--;
		return (substr_alter(s1, 0, i + 1));
	}
}

char	*another_strtrim(char *s1, char *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

char	*substr_alter(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
	{
		return (NULL);
	}
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[len] = '\n';
	str[len + 1] = '\0';
	return (str);
}

int	line_is_empty(char *str)
{
	if (!str || !*str || *str == '\n'
		|| *str == ' ' || *str == '\t'
		|| *str == '\v')
	{
		return (1);
	}
	return (0);
}
