# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abasante <abasante@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:08:47 by abasante          #+#    #+#              #
#    Updated: 2023/11/22 13:41:37 by abasante         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cubed

CC = gcc

SRC = cub3d.c \
	utils_parse1_elem.c \
	utils_parse2_elem.c \
	parse_elements.c \
	parse_map.c \
	libft/get_next_line.c \

INCLUDES = -I./libft

LIBS = -L./libft -lft #-Lmlx -lmlx  -framework OpenGL -framework AppKit

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

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

re: fclean all

.PHONY: all clean fclean re