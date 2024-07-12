/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <ashahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:09:56 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/07/12 15:36:42 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(int x)
{
	char	c;

	c = x + '0';
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	res;

	res = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10);
	}
	else
		ft_putchar(nb);
}

void	double_new_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i] && line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			error("Validation failed!\n", line);
		i++;
	}
}
