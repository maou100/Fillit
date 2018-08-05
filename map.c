/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:34:22 by feedme            #+#    #+#             */
/*   Updated: 2018/06/06 20:26:46 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * size)))
		ft_error();
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(size + 1)))
			ft_error();
		j = -1;
		while (++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	return (map);
}

void	ft_putmap(char **map)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (map[0][count])
		count++;
	while (++i < count)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

void	ft_del_coords(int **coords, int block)
{
	int		i;

	i = 0;
	while (++i < block)
		free(coords[i]);
	free(coords);
}
