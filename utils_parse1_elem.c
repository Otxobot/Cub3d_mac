/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:26 by abasante          #+#    #+#             */
/*   Updated: 2023/11/16 19:28:38 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int is_cub(char *string)
{
	int i;

	i = 0;
	i = ft_strlen(string) - 1;

	if (string[i--] != 'b')
		return (1);
	if (string[i--] != 'u')
		return (1);
	if (string[i--] != 'c')
		return (1);
	if (string[i--] != '.')
		return (1);
	return (0);
}

int	empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == 32 || line[i] == 9 || line[i] == '\n')
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int check_for_NOSOWEEAFC(char *string)
{
	int i;

	i = 0;
	while (string[i] && string[i] == ' ')
		i++;
	if ((string[i] == 'N' && string[i + 1] == 'O') && (string[i + 2] == ' ' || string[i + 2] == '	'))
		return (TRUE);
	else if ((string[i] == 'S' && string[i + 1] == 'O') && (string[i + 2] == ' ' || string[i + 2] == '	'))
		return (TRUE);
	else if ((string[i] == 'W' && string[i + 1] == 'E') && (string[i + 2] == ' ' || string[i + 2] == '	'))
		return (TRUE);
	else if ((string[i] == 'E' && string[i + 1] == 'A') && (string[i + 2] == ' ' || string[i + 2] == '	'))
		return (TRUE);
	else if (string[i] == 'F' && (string[i + 1] == ' ' || string[i + 1] == '	'))
		return (TRUE);
	else if (string[i] == 'C' && (string[i + 1] == ' ' || string[i + 1] == '	'))
		return (TRUE);
	return (FALSE);
}

void	put_each_route_in_place_in_struct(char identifier, char *path_to_save_in_struct, t_info *info)
{
	if (identifier == 'N')
		info->no_texture = path_to_save_in_struct;
	else if (identifier == 'S')
		info->so_texture = path_to_save_in_struct;
	else if (identifier == 'W')
		info->we_texture = path_to_save_in_struct;
	else if (identifier == 'E')
		info->ea_texture = path_to_save_in_struct;
}

void	put_each_RGB_in_place_in_struct(char identifier_RGB, char *RGB, t_info *info)
{
	if (identifier_RGB == 'F')
		info->f_color = RGB;
	else if (identifier_RGB == 'C')
		info->c_color = RGB;
}
