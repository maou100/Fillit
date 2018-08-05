/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:09:29 by feedme            #+#    #+#             */
/*   Updated: 2018/06/06 16:01:01 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_tetri(char *buf, int *coords, int i)
{
	int		j;
	int		x;
	int		y;

	j = 0;
	x = 0;
	y = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			coords[j] = x;
			coords[j + 1] = y;
			j += 2;
			x++;
		}
		else if (buf[i] == '.')
			x++;
		else
		{
			x = 0;
			y++;
		}
		i++;
	}
}

int		ft_check_block(char *buf)
{
	int		i;
	int		links;

	links = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i > 0 && buf[i - 1] == '#')
				links++;
			if (buf[i + 1] == '#')
				links++;
			if (i > 4 && buf[i - 5] == '#')
				links++;
			if (i < 14 && buf[i + 5] == '#')
				links++;
		}
		i++;
	}
	if (links == 6 || links == 8)
		return (1);
	else
		return (0);
}

int		ft_check_links(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (ft_check_block(&buf[i]) == 0)
			return (0);
		i += 21;
	}
	return (1);
}

int		ft_get_coords(int **coords, char *buf, int block)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (ft_check_links(buf) == 0)
		return (0);
	while (j < block)
	{
		ft_get_tetri(&buf[i], coords[j], 0);
		i += 21;
		j++;
	}
	return (1);
}
