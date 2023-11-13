/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:09 by abasante          #+#    #+#             */
/*   Updated: 2023/11/13 18:15:09 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
Esta funcion tiene que coger el .cub y meter toda la informacion que hay dentro y comparitmentarlo de manera correcta.
Primero van las texturas de norte, sur, oeste y este. NO, SO, WE, EA son los identificadores que van antes de cada elemento.
Segundo van dos colres RGB, el que va a estar en la parte del cielo y la que va a estar en la parte del suelo, dividido por el horizonte por asi decirlo.
Van a ser F (suelo) y C (techo). 
Y finalmente va a ir el mapa, que por ahora es el mas dificil y el cual dejare para el final. 
*/

t_info *extract_text(char *file_path)
{
	int fd;
	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	t_info *info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	char *line;
	line = get_next_line(fd);
	printf("%s\n", line);
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%s\n", line);
	// 	//if (ft_strnstr)
	// }
	return (NULL);
}
