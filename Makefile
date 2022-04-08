# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:23:37 by rgirondo          #+#    #+#              #
#    Updated: 2022/04/07 18:27:42 by rgirondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d

CC=gcc

CFLAGS=-Wall -Wextra -Werror

CMLX=-I /usr/local/include -g -L /usr/local/lib -lmlx \
	-framework OpenGL -framework AppKit

HEADER=./cub3d.h ./ft_printf/ft_printf.h

RM=rm -f

SRC= ./main.c

OBJ=$(SRC:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ) $(HEADER)
		cd ./ft_printf/ && make
		$(CC) $(CFLAGS) $(CMLX) -L ./ft_printf/ -lftprintf\
		-o $(NAME) $(OBJ) 

clean:
		cd ./ft_printf/ && make fclean
		$(RM) $(OBJ)

fclean: clean
		$(RM)
		rm $(NAME)

re: fclean all

.PHONY: all clean fclean re