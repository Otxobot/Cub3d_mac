/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_walls_closed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:07:32 by abasante          #+#    #+#             */
/*   Updated: 2023/12/05 13:38:27 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int check_if_walls_closed(char **map)
{
	/*for this function I am going to have to reallocate an entire line of * 
	at the top line of the map and at the bottom line of the map.
	
	Also the spaces that aren't spaces yet, 
	i want to make a good rectangle out of the map so that it is easier to do flood fill.*/
	int		i;
	int		j;
	int		longest_line_size;
	char	**map_for_flood_fill;

	longest_line_size = calc_longest_line(map);
	map_for_flood_fill = create_map_for_flood_fill(map, longest_line_size);
	printf("longest_line_size:%d\n", longest_line_size);
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] != '0'))
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
