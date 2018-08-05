/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:53:37 by feedme            #+#    #+#             */
/*   Updated: 2018/06/06 15:59:46 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_x_range(int *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = str[i];
	while (i < 8)
	{
		if (str[i] < ret)
			ret = str[i];
		i += 2;
	}
	return (ret);
}

int		ft_y_range(int *str)
{
	int		i;
	int		ret;

	i = 1;
	ret = str[i];
	while (i < 8)
	{
		if (str[i] < ret)
			ret = str[i];
		i += 2;
	}
	return (ret);
}

void	ft_translation(int **array, int block, int i)
{
	int		x;
	int		y;
	int		xi;
	int		yi;
	int		count;

	while (++i < block)
	{
		count = 0;
		xi = 0;
		yi = 1;
		x = ft_x_range(array[i]);
		y = ft_y_range(array[i]);
		while (count < 4)
		{
			array[i][xi] -= x;
			array[i][yi] -= y;
			xi += 2;
			yi += 2;
			count++;
		}
	}
}

int		ft_get_tet(char *file, int **coords, int block)
{
	int		fd;
	char	*buf;
	int		i;

	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (!(buf = (char *)malloc(21 * block + 1)))
		return (0);
	buf[21 * block - 1] = '\0';
	buf[21 * block] = '\0';
	if (read(fd, buf, 21 * block - 1) == -1)
		return (0);
	if (ft_get_coords(coords, buf, block) == 0)
		return (0);
	ft_translation(coords, block, -1);
	free(buf);
	if (close(fd) == -1)
		return (0);
	return (1);
}
