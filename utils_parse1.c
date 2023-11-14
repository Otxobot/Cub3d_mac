/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:26 by abasante          #+#    #+#             */
/*   Updated: 2023/11/14 16:45:10 by abasante         ###   ########.fr       */
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
