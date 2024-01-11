/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:09 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 17:38:24 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char	**no_empty_lines(char *file_path, char **lines_ws)
{
	int		fd1;
	int		i;
	int		elements;
	int		nada;
	char	*line;

	nada = 0;
	fd1 = open(file_path, O_RDONLY);
	i = 0;
	elements = 0;
	line = get_next_line(fd1);
	while (line)
	{
		if (check_for_elements(line))
			elements++;
		if (elements != 6)
			nada++;
		if (elements != 6 && empty_line(line))
			nada++;
		else
			lines_ws[i++] = line;
		line = get_next_line(fd1);
	}
	lines_ws[i] = NULL;
	return ((close(fd1)), lines_ws);
}

char	**extract_elements(char *file_path, int a, int nada, int elements)
{
	int		fd;
	char	**lines_ws;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	line = get_next_line(fd);
	lines_ws = NULL;
	while (line)
	{
		if (check_for_elements(line))
			elements++;
		if (elements != 6)
			if (empty_line(line))
				nada++;
		if (elements != 6 && empty_line(line))
			nada++;
		else
			a++;
		free(line);
		line = get_next_line(fd);
	}
	return (lines_ws = maloc_lines_ws(lines_ws, a, file_path, fd));
}

int	categorize_elements(char **elements, t_info *info)
{
	int		i;
	char	identifier;
	int		all_elements_done;

	i = 0;
	all_elements_done = 0;
	while (elements[i])
	{
		if (all_elements_done == 6)
			break ;
		identifier = check_identifier(elements[i]);
		if (identifier == 'N' || identifier == 'E' \
		|| identifier == 'S' || identifier == 'W')
		{
			if (!check_for_correct_path(elements[i], info, 0, 0))
				return (printf("Error\nOne path is incorrect!\n"), FALSE);
		}
		else if (identifier == 'F' || identifier == 'C')
			if (!check_for_correct_rgb(elements[i], info, identifier))
				return (printf("Error\nOne of RGBs is incorrect!\n"), FALSE);
		i++;
		all_elements_done++;
	}
	return (TRUE);
}

char	bucle_hasta_letra(char *element, int *i, char identifier)
{
	while (element[*i] != 'N' && element[*i] != 'S' \
		&& element[*i] != 'W' && element[*i] != 'E')
		*i += 1;
	identifier = element[*i];
	while (element[*i] && element[*i] != '.')
		*i += 1;
	return (identifier);
}

int	check_for_correct_path(char *element, t_info *info, int i, size_t len)
{
	int		start;
	char	*ptsis;
	char	identifier;

	identifier = 0;
	while (element[i])
	{
		identifier = bucle_hasta_letra(element, &i, identifier);
		if (element[i] && element[i] != '.' && element[i + 1] != '/')
			return (FALSE);
		start = i;
		while (ft_isprint(element[i]) && element[i] != 32 && element[i] != 9)
		{
			i++;
			len++;
		}
		ptsis = ft_substr(element, start, len);
		if (!termina_con_xpm(ptsis))
			return (FALSE);
		if (ptsis[2] == 32 || ptsis[2] == 9 || ptsis[2] == '\0')
			return (FALSE);
		put_each_route_in_place_in_struct(identifier, ptsis, info);
		return (free(ptsis), TRUE);
	}
	return (FALSE);
}
