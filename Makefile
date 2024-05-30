# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feljourb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 20:18:39 by feljourb          #+#    #+#              #
#    Updated: 2024/05/29 02:00:32 by feljourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c Utils/so_long_utils.c Gnl/get_next_line_utils.c Gnl/get_next_line.c \
		ft_error.c checks.c Utils/so_long_utils2.c Utils/so_long_utils3.c checks1.c \
		

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re fclean all 