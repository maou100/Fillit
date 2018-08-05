# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feedme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/31 17:32:08 by feedme            #+#    #+#              #
#    Updated: 2018/06/07 14:54:31 by apickett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror
SRC = ft_get_coords.c ft_get_tet.c ft_solver.c main.c map.c helper.c
OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

all: $(NAME)

$(NAME): 
	$(CC) $(FLAGS) $(SRC) -c
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
