/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:26 by abasante          #+#    #+#             */
/*   Updated: 2023/11/16 14:48:23 by abasante         ###   ########.fr       */
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
