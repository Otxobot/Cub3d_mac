/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:18:18 by abasante          #+#    #+#             */
/*   Updated: 2023/01/12 16:52:58 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

                /* FUNCTIONS */
char *get_next_line(int fd);

char *ft_get_line(char *save);

char *ft_save(char *save);

char *ft_read_and_save(int fd, char *save);

            /* FUNCTIONS FROM LIBFT */
size_t ft_strlen(char *str);

char *ft_strchr(char *s, int c);

char *ft_strjoin(char *s1, char *s2);

void *ft_memcpy(void *dst, const void *src, size_t n);

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);

#endif
