NAME = libft.a

SRC = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memcmp.c\
		ft_memchr.c\
		ft_strnstr.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putnbr_fd.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_split.c\
		get_next_line.c \
		ft_double_free.c \

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)

all: $(NAME)

$(OBJ): $(SRC) 
	gcc -c $(CFLAGS) $(SRC)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	ar $(NAME) $(OBJ) $(OBJ_B)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
