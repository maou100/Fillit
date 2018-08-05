/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:50:18 by feedme            #+#    #+#             */
/*   Updated: 2018/06/08 13:27:54 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_wrong_params(void)
{
	ft_putstr("usage : ./fillit file_name\n");
	exit(0);
}

int	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int	ft_check_err(int fd, int hash, int i, int block)
{
	char	c;

	while (read(fd, &c, 1) > 0)
	{
		if (c == '#')
			hash++;
		if (++i % 5 == 0)
			if (c != '\n')
				return (0);
		if (i % 5 != 0)
			if (c != '.' && c != '#')
				return (0);
		if (i == 20)
		{
			if (hash != 4)
				return (0);
			hash = 0;
			block++;
			i = -1;
		}
	}
	if (i != -1 || block > 26)
		return (0);
	return (block);
}

int	main(int ac, char **av)
{
	int		fd;
	int		block;
	int		i;
	t_hippo	hippo;

	i = -1;
	if (ac != 2)
		return (ft_wrong_params());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error());
	if ((block = ft_check_err(fd, 0, 0, 0)) == 0)
		return (ft_error());
	if (!(hippo.coords = (int **)malloc(sizeof(int *) * (block + 1))))
		return (ft_error());
	hippo.coords[block] = NULL;
	while (++i < block)
		if (!(hippo.coords[i] = (int *)malloc(sizeof(int) * 8)))
			return (0);
	if (close(fd) == -1)
		return (ft_error());
	if (ft_get_tet(av[1], hippo.coords, block) == 0)
		return (ft_error());
	ft_solver(hippo, block);
	return (0);
}
