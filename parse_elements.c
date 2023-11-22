/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:09 by abasante          #+#    #+#             */
/*   Updated: 2023/11/22 18:25:59 by abasante         ###   ########.fr       */
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
			ft_double_free (elements);
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
	int	j;
	char	identifier;

	i = 0;
	j = 0;
	while (elements[i])
	{
		identifier = check_identifier(elements[i]);
		if (identifier == 'N' || identifier == 'E' || identifier == 'S' || identifier == 'W')
			check_for_correct_path(elements[i], info);
		else if (identifier == 'F'  || identifier == 'C')
			check_for_correct_RGB(elements[i], info);
		i++;
	}
	return (TRUE);
}

int check_for_correct_RGB(char *element, t_info *info)
{
	/*The correct approach would probably be to split with comas, then eliminate characters, then eliminate spaces
	and then get each number that is a string and convert it to a int. 
	
	This way I can then check to see if it is max 255, and it will be easier to manage later.*/
	
	printf("-->%s\n", element);
	char	**num;
	num = ft_split (element, ',');

	printf("num1:%s\n", num[0]);
	printf("num2:%s\n", num[1]);
	printf("num3:%s\n", num[2]);
	info = NULL;
	return (TRUE);
}

// int	check_for_correct_RGB(char *element, t_info *info)
// {
// 	int 	i;
// 	int		check_for_letters;
// 	int		start;
// 	int		end;
// 	int		coma;
// 	char	identifier_RGB;
// 	char	*RGB;

// 	i = 0;
// 	coma = 0;
// 	check_for_letters = 0;
// 	while (element[i])
// 	{
// 		while (element[i] != 'F' && element[i] != 'C')
// 		{
// 			check_for_letters++;
// 			i++;
// 		}
// 		identifier_RGB = element[i];
// 		while (element[i] && (!ft_isdigit(element[i])))
// 		{
// 			check_for_letters++;
// 			i++;
// 		}
// 		start = i;
// 		while (element[check_for_letters])
// 		{
// 			if (ft_isalpha(element[check_for_letters]))
// 				return (FALSE);
// 			check_for_letters++;
// 		}
// 		if(!check_if_numbers_are_correct_size1(&element[start]))
// 			return (FALSE);
// 		while (element[i] && (ft_isdigit(element[i]) || element[i] == ',') && coma <= 2)
// 		{
// 			if (element[i] == ',')
// 				coma += 1;
// 			i++;
// 		}
// 		end = i;
// 		RGB = ft_substr(element, start, end - start);
// 		put_each_RGB_in_place_in_struct(identifier_RGB, RGB, info);
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }

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
		if (element[i] != '.' && element[i + 1] != '/')
			return (FALSE);
		start = i;
		while (ft_isprint(element[i]) && element[i] != 32 && element[i] != 9)
		{
			i++;
			len++;
		}
		path_to_save_in_struct = ft_substr(element, start, len);
		if (path_to_save_in_struct[2] == 32 || path_to_save_in_struct[2] == 9 \
		|| path_to_save_in_struct[2] == '\0')
			return (FALSE);
		put_each_route_in_place_in_struct(identifier, path_to_save_in_struct, info);
		return (TRUE);
	}
	return (FALSE);
}

