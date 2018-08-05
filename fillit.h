/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:48:20 by feedme            #+#    #+#             */
/*   Updated: 2018/06/07 14:55:09 by apickett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef	struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef	struct		s_hippo
{
	int				**coords;
	int				size;
}					t_hippo;

int					ft_solvit(char **map, t_hippo hippo, int i, char letter);
int					ft_scan(char **map, int *coords, int size, t_xy xy);
void				ft_rm_tet(char **map, int *coords, int x, int y);
void				ft_put_tet(char **map, int *coords, t_xy xy, char letter);
void				ft_putmap(char **map);
char				**ft_create_map(int size);
void				ft_del_coords(int **coords, int block);
int					ft_wrong_params(void);
int					ft_error(void);
int					ft_check_err(int fd, int hash, int i, int block);
void				ft_solver(t_hippo hippo, int block);
int					ft_x_range(int *str);
int					ft_y_range(int *str);
void				ft_translation(int **array, int block, int i);
int					ft_get_tet(char *file, int **coords, int block);
void				ft_get_tetri(char *buf, int *coords, int i);
int					ft_check_block(char *buf);
int					ft_check_links(char *buf);
int					ft_get_coords(int **coords, char *buf, int block);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(char const *s);
void				ft_strdel(char **as);

#endif
