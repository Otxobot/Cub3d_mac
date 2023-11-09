# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abasante <abasante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:08:47 by abasante          #+#    #+#              #
#    Updated: 2023/11/09 17:14:13 by abasante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cubed

CC = gcc

SRC = main.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB_FLAGS)

clean:
	@rm -rf $(OBJ)
	@rm -rf ./a.out

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re