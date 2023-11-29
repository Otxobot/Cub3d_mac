/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse1_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:26 by abasante          #+#    #+#             */
/*   Updated: 2023/11/29 15:41:03 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

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
	while (string[i] && (string[i] == ' ' || string[i] == '	'))
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

int check_for_NOSOWEEAFC_no_repeats(char *string)
{
	static char lastCondition = '\0';  // Static variable to keep track of the last condition

    int i = 0;
    while (string[i] && (string[i] == ' ' || string[i] == '\t'))
        i++;
    // Check conditions and ensure they haven't been true in the last iteration
    if (((string[i] == 'N' && string[i + 1] == 'O') && (string[i + 2] == ' ' || string[i + 2] == '\t')) && lastCondition != 'N')
    {
        lastCondition = 'N';
        return TRUE;
    }
    else if (((string[i] == 'S' && string[i + 1] == 'O') && (string[i + 2] == ' ' || string[i + 2] == '\t')) && lastCondition != 'S')
    {
        lastCondition = 'S';
        return TRUE;
    }
    else if (((string[i] == 'W' && string[i + 1] == 'E') && (string[i + 2] == ' ' || string[i + 2] == '\t')) && lastCondition != 'W')
    {
        lastCondition = 'W';
        return TRUE;
    }
    else if (((string[i] == 'E' && string[i + 1] == 'A') && (string[i + 2] == ' ' || string[i + 2] == '\t')) && lastCondition != 'E')
    {
        lastCondition = 'E';
        return TRUE;
    }
    else if (string[i] == 'F' && (string[i + 1] == ' ' || string[i + 1] == '\t') && lastCondition != 'F')
    {
        lastCondition = 'F';
        return TRUE;
    }
    else if (string[i] == 'C' && (string[i + 1] == ' ' || string[i + 1] == '\t') && lastCondition != 'C')
    {
        lastCondition = 'C';
        return TRUE;
    }

    lastCondition = '\0';  // Reset lastCondition if none of the conditions are true
    return FALSE;
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

