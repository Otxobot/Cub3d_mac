/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:09 by abasante          #+#    #+#             */
/*   Updated: 2023/12/12 10:01:37 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char **no_empty_lines(char *file_path, char **lines_ws)
{
	int fd1;
	int i;
	int elements;
	int nada;
	char *line;

	nada = 0;
	fd1 = open(file_path, O_RDONLY);
	i = 0;
	elements = 0;
	while ((line = get_next_line(fd1)) != NULL)
	{
		if (check_for_NOSOWEEAFC(line))
			elements++;
		if (elements != 6)
		{
			nada++;
		}
		if (elements != 6 && empty_line(line))
			nada++;
		else
		{
			lines_ws[i++] = line;
			//free (line);
		}
	}
	lines_ws[i] = NULL;
	return(lines_ws);
}

char **extract_elements(char *file_path)
{
	int fd;
	int a;
	int nada;
	int elements;
	char **lines_ws;
	char *line;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	a = 0;
	nada = 0;
	elements = 0;
	lines_ws = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (check_for_NOSOWEEAFC(line))
			elements++;
		if (elements != 6)
		{
			if (empty_line(line))
				nada++;
		}
		if (elements != 6 && empty_line(line))
			nada++;
		else
			a++;
		free (line);
	}
	lines_ws = malloc(sizeof(char *) * (a + 1));
	close(fd);
	lines_ws = no_empty_lines(file_path, lines_ws);
	return (lines_ws);
}

int	check_if_all_elements(char **elements)
{
	int i;
	int	all_elements_done;

	all_elements_done = 0;
	i = 0;
	while (elements[i])
	{
		if (all_elements_done == 6)
			break;
		if (!check_for_NOSOWEEAFC(elements[i]))
		{
			printf("Error\nDidn't find one of the elements\n");
			ft_double_free (elements);
			return (FALSE);
		}
		all_elements_done++;
		i++;
	}
	return (TRUE);
}

int	categorize_elements(char **elements, t_info *info)
{
	int i;
	char	identifier;
	int		all_elements_done;

	i = 0;
	all_elements_done = 0;
	while (elements[i])
	{
		if (all_elements_done == 6)
			break;
		identifier = check_identifier(elements[i]);
		if (identifier == 'N' || identifier == 'E' || identifier == 'S' || identifier == 'W')
		{
			if (!check_for_correct_path(elements[i], info))
				return (printf("Error\nOne of the paths is incorrect!\n"), FALSE);
		}
		else if (identifier == 'F'  || identifier == 'C')
		{
			if (!check_for_correct_RGB(elements[i], info, identifier))
				return (printf("Error\nOne of RGBs is incorrect!\n"), FALSE);
		}
		i++;
		all_elements_done++;
	}
	return (TRUE);
}

int check_for_correct_RGB(char *element, t_info *info, char identifier)
{
	int i;
	char *set = "FC 	";
	char *letse;
	char **nums;

	i = 0;
	letse = ft_strtrim(element, set);
	while (letse[i])
	{
		if (ft_isalpha(letse[i]))
			return (FALSE);
		i++;
	}
	nums = ft_split(letse, ',');
	if (nums[0] == NULL || nums[1] == NULL || nums[2] == NULL)
		return (FALSE);
	if (!RGB_atois(identifier, nums, info))
		return (FALSE);
	free (letse);
	ft_double_free(nums);
	return (TRUE);
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
		if (element[i] && element[i] != '.' && element[i + 1] != '/')
			return (FALSE);
		start = i;
		while (ft_isprint(element[i]) && element[i] != 32 && element[i] != 9)
		{
			i++;
			len++;
		}
		path_to_save_in_struct = ft_substr(element, start, len);
		if (!termina_con_xpm(path_to_save_in_struct))
			return (FALSE);
		if (path_to_save_in_struct[2] == 32 || path_to_save_in_struct[2] == 9 \
		|| path_to_save_in_struct[2] == '\0')
			return (FALSE);
		put_each_route_in_place_in_struct(identifier, path_to_save_in_struct, info);
		free (path_to_save_in_struct);
		return (TRUE);
	}
	return (FALSE);
}
