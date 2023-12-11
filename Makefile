# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:08:47 by abasante          #+#    #+#              #
#    Updated: 2023/12/11 11:16:10 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cubed

CC = gcc

SRC = cub3d.c \
	elements/utils_parse1_elem.c \
	elements/utils_parse2_elem.c \
	elements/parse_elements.c \
	map/parse_map.c \
	map/map_utils1.c \
	map/map_utils2.c \
	libft/get_next_line.c \
	free.c \

INCLUDES = -I./libft

LIBS = -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS)  -o $(NAME) $(LIB_FLAGS)

clean:
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf ./a.out

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf cubed.dSYM

re: fclean all

.PHONY: all clean fclean re