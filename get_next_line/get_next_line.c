/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:18:11 by abasante          #+#    #+#             */
/*   Updated: 2023/01/16 12:14:01 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(char *save) 
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}
 
char *ft_save(char *save)
{
    int i;
    char *str;
    for (i = 0; save[i] && save[i] != '\n'; i++);
    if (!save[i])
    {
        free(save);
        return NULL;
    }
    str = malloc(ft_strlen(save + 1) + 1);
    if (!str)
        return NULL;
    ft_strlcpy(str, save + i + 1, ft_strlen(save + i + 1) + 1);
    free(save);
    save = NULL;
    return str;
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	buff = NULL;
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("Error buffer size is less than %d\n", BUFFER_SIZE);
		return (0);
	}
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
