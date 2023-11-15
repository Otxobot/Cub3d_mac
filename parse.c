/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:09 by abasante          #+#    #+#             */
/*   Updated: 2023/11/14 16:58:08 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
Esta funcion tiene que coger el .cub y meter toda la informacion que hay dentro y compartimentarlo de manera correcta.
Primero van las texturas de norte, sur, oeste y este. NO, SO, WE, EA son los identificadores que van antes de cada elemento.
Segundo van dos colres RGB, el que va a estar en la parte del cielo y la que va a estar en la parte del suelo, dividido por el horizonte.
Van a ser F (suelo) y C (techo). 
Y finalmente va a ir el mapa, que por ahora es el mas dificil y el cual dejare para el final. 
*/

char **no_empty_lines(char *file_path, char **lines_ws, char *line)
{
	int fd1;
	int i;
	int nada;

	nada = 0;
	fd1 = open(file_path, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd1)) != NULL)
	{
		if (empty_line(line))
			nada++;
		else
			lines_ws[i++] = line;
	}
	lines_ws[i] = NULL;
	return(lines_ws);
}

char **extract_elements(char *file_path)
{
	int fd;
	int a;
	int nada;
	char **lines_ws;
	char *line;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	a = 0;
	nada = 0;
	lines_ws = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (empty_line(line))
			nada++;
		else
			a++;
	}
	lines_ws = malloc(sizeof(char *) * ( a + 1));
	close(fd);
	no_empty_lines(file_path, lines_ws, line);
	free(line);
	return (lines_ws);
}

int check_for_NO(char *string)
{
	int i;

	i = 0;
	while (string[i] && string[i] != 'N')
		i++;
	if (string[i + 1] == 'O' && string[i + 2] == 32)
	{
		printf("%c%c\n", string[i], string[i + 1]);
		return (0);
	}
	return (1);
}

int check_for_SO(char *string)
{
	int i;

	i = 0;
	printf("char:%c\n", string[i]);
	while (string[i] && string[i] != 'S')
		i++;
	if (string[i + 1] == 'O' && string[i + 2] == 32)
	{
		printf("%c%c\n", string[i], string[i + 1]);
		return (0);
	}
	return (1);
}

t_elem	init_elements_id()
{
	t_elem elements;

	strcpy(elements.NO, "NO");
	strcpy(elements.SO, "SO");
	strcpy(elements.WE, "WE");
	strcpy(elements.EA, "EA");
	strcpy(elements.F, "F");
	strcpy(elements.C, "C");

	return (elements);
}

// int check_for_NOSOWEEAFC(char *string, t_elem elements_id)
// {

// }

int	check_if_all_elements(char **elements)
{
	//I have to check and see if there is NO, SO, WE, EA, F and C in each line.
	int i;
	t_elem elements_id;

	i = 0;
	elements_id = init_elements_id();
	printf("just to silence:%s\n", elements[1]);
	while (elements[i])
	{
		if (check_for_NOSOWEEAFC(elements[i], elements_id))
		{
			printf("didn't find one of the elements\n");	
			return (1);
		}
		i++;
	}
	// if (check_for_NO(elements[i]))
	// {
	// 	printf("didn't find NO\n");
	// 	return (1);
	// }
	// i++;
	// if (check_for_SO(elements[i]))
	// {
	// 	printf("didn't find SO\n");
	// 	return (1);
	// }
	return (0);
}
