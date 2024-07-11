# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feljourb <feljourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 20:18:39 by feljourb          #+#    #+#              #
#    Updated: 2024/07/11 21:22:27 by feljourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLXFLAG = -lmlx -lXext -lX11
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c Utils/so_long_utils.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
		check_map/ft_error.c check_map/check_caracteres.c Utils/so_long_utils2.c Utils/so_long_utils3.c check_map/check_murs.c \
		check_map/flood_fill.c check_map/check_all.c check_map/init_map.c game/mouvement.c check_map/free_map.c \
		game/load_img.c game/draw_map.c game/init_game.c game/ft_hook.c game/print_mouv.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAG) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re fclean all 