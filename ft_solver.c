/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:01:12 by feedme            #+#    #+#             */
/*   Updated: 2018/06/07 14:55:14 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_tet(char **map, int *coords, t_xy xy, char letter)
{
	int		count;
	int		xi;
	int		yi;

	count = 0;
	while (count < 8)
	{
		xi = coords[count];
		yi = coords[count + 1];
		map[xy.y + yi][xy.x + xi] = letter;
		count += 2;
	}
}

void	ft_rm_tet(char **map, int *coords, int x, int y)
{
	int		count;
	int		xi;
	int		yi;

	count = 0;
	while (count < 8)
	{
		xi = coords[count];
		yi = coords[count + 1];
		map[y + yi][x + xi] = '.';
		count += 2;
	}
}

int		ft_scan(char **map, int *coords, int size, t_xy xy)
{
	int		count;
	int		xi;
	int		yi;

	count = 0;
	while (count < 8)
	{
		xi = coords[count];
		yi = coords[count + 1];
		if (xy.x + xi < size && xy.y + yi < size)
		{
			if (map[xy.y + yi][xy.x + xi] != '.')
				return (0);
		}
		else
			return (0);
		count += 2;
	}
	return (1);
}

int		ft_solvit(char **map, t_hippo hippo, int i, char letter)
{
	t_xy	xy;

	if (!hippo.coords[i])
		return (1);
	xy.y = -1;
	while (++xy.y < hippo.size)
	{
		xy.x = -1;
		while (++xy.x < hippo.size)
		{
			if (ft_scan(map, hippo.coords[i], hippo.size, xy))
			{
				ft_put_tet(map, hippo.coords[i], xy, letter);
				if (ft_solvit(map, hippo, i + 1, letter + 1))
					return (1);
				ft_rm_tet(map, hippo.coords[i], xy.x, xy.y);
			}
		}
	}
	return (0);
}

void	ft_solver(t_hippo hippo, int block)
{
	int		i;
	int		booly;
	char	**map;

	booly = 0;
	hippo.size = 1;
	while (!booly)
	{
		hippo.size++;
		map = ft_create_map(hippo.size);
		booly = ft_solvit(map, hippo, 0, 'A');
		if (booly)
			ft_putmap(map);
		i = -1;
		while (++i < hippo.size)
			ft_strdel(&(map[i]));
	}
	ft_del_coords(hippo.coords, block);
}
