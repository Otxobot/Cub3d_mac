/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:09 by abasante          #+#    #+#             */
/*   Updated: 2023/11/16 19:34:47 by abasante         ###   ########.fr       */
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
	lines_ws = malloc(sizeof(char *) * (a + 1));
	close(fd);
	no_empty_lines(file_path, lines_ws, line);
	free(line);
	return (lines_ws);
}

int	check_if_all_elements(char **elements)
{
	/*I have to check and see if there is NO, SO, WE, EA, F and C in each line. 
	For now i think it is good, it is still to be seen if these two functions won't cause any problems
	or errors in the future. I'll leave this here to see.*/
	int i;

	i = 0;
	while (elements[i])
	{
		if (!check_for_NOSOWEEAFC(elements[i]))
		{
			printf("didn't find one of the elements\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}


int	categorize_elements(char **elements, t_info *info)
{
	/*In this function I have to check the route of each texture to see first if it is correct 
	and put them in their char * in the structure,
	After that I will make a function that first checks to see if the RGB numbers are correct and then also puts them
	into their respective integer inside of the struct.*/
	int i;

	i = 0;
	while (elements[i])
	{
		if (i < 4)
		{
			if (!check_for_correct_path(elements[i], info))
			{
				printf("One of the textures is incorrect!\n");
				return (FALSE);
			}
			i++;
		}
		else
		{
			if (!check_for_correct_RGB(elements[i], info))
			{
				printf("One of the RGBS is incorrect!\n");
				return (FALSE);
			}
			i++;
		}
	}
	printf("info->NO_texture:%s\n", info->no_texture);
	printf("info->SO_texture:%s\n", info->so_texture);
	printf("info->WE_texture:%s\n", info->we_texture);
	printf("info->EA_texture:%s\n", info->ea_texture);
	printf("%s\n", info->f_color);
	printf("%s\n", info->c_color);
	return (TRUE);
}

int	check_for_correct_RGB(char *element, t_info *info)
{
	int 	i;
	int		start;
	int		end;
	int		coma;
	char	identifier_RGB;
	char	*RGB;

	i = 0;
	coma = 0;
	while (element[i])
	{
		while (element[i] != 'F' && element[i] != 'C')
			i++;
		identifier_RGB = element[i];
		while (element[i] && (!ft_isdigit(element[i])))
			i++;
		start = i;
		while (element[i] && (ft_isdigit(element[i]) || element[i] == ',') && coma <= 2)
		{
			if (element[i] == ',')
				coma += 1;
			i++;
		}
		end = i;
		RGB = ft_substr(element, start, end - start);
		put_each_RGB_in_place_in_struct(identifier_RGB, RGB, info);
		return (TRUE);
	}
	return (FALSE);
}

int check_for_correct_path(char *element, t_info *info)
{
	int		i;
	int 	start;
	size_t	len;
	char	*path_to_save_in_struct;
	char	identifier;

	i = 0;
	len = 0;
	while (element[i])
	{	
		while (element[i] != 'N' && element[i] != 'S' && element[i] != 'W' && element[i] != 'E')
			i++;
		identifier = element[i];
		while (element[i] && element[i] != '.')
			i++;
		start = i;
		while (ft_isprint(element[i]) && element[i] != 32 && element[i] != 9)
		{
			i++;
			len++;
		}
		path_to_save_in_struct = ft_substr(element, start, len);
		put_each_route_in_place_in_struct(identifier, path_to_save_in_struct, info);
		return (TRUE);
	}
	return (FALSE);
}

