# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:08:47 by abasante          #+#    #+#              #
#    Updated: 2024/01/10 17:05:41 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

SRC = cub3d.c \
	elements/utils_parse1_elem.c \
	elements/utils_parse2_elem.c \
	elements/parse_elements.c \
	map/parse_map.c \
	map/map_utils1.c \
	map/map_utils2.c \
	map/map_utils3.c \
	map/map_utils_utils.c \
	map/check_if_walls_closed.c \
	libft/get_next_line.c \
	free.c \
	parse.c \
	load_screen/load_screen1.c \
	load_screen/load_screen2.c \
	load_screen/load_screen_utils.c \
	load_screen/paint_back.c \
	movement/events.c \
	init_values.c \
	textures/init_textures.c \
	textures/init_textures1.c 

INCLUDES = -I./libft

LIBS =  -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
#LIBS = -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
	@rm -rf cub3d.dSYM

re: fclean all

.PHONY: all clean fclean re