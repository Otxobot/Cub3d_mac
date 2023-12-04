/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:22 by abasante          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:24 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int see_if_there_is_no_more_map(char **string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (empty_line(string[i]))
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int check_if_walls_closed(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '1' || map[i][j] == '\n'))
		{
			j++;
		}
		if (map[i][j] == '0')
		{
			flood_fill(i, j, map);
			int a = 0;
			while (map[a])
				printf("%s", map[a++]);
			break;
		}
		i++;
	}
	return (TRUE);
}

void	flood_fill(int x, int y, char **map)
{
	int h;
	int w;

	h = 0;
	w = 0;
	if (map[x][y] != '0' || map[x][y + 1] == '\n')
	{
		return;
	}
    if(map[x][y] != 'F')
		map[x][y] = 'F';

    w = ft_strlen(map[x]);
    flood_fill(x+1, y, map);
    flood_fill(x-1, y, map);
    flood_fill(x, y+1, map);
    flood_fill(x, y-1, map);
}
