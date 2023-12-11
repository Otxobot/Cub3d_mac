/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_walls_closed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:07:32 by abasante          #+#    #+#             */
/*   Updated: 2023/12/11 11:09:54 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int check_if_walls_closed(char **map)
{
	/*for this function I am going to have to reallocate an entire line of * 
	at the top line of the map and at the bottom line of the map.
	
	Also the spaces that aren't spaces yet, 
	i want to make a good rectangle out of the map so that it is easier to do flood fill.*/
	int		longest_line_size;
	int		amount_of_lines;
	char	**map_for_flood_fill;

	longest_line_size = calc_longest_line(map);
	amount_of_lines = calc_amount_of_lines(map);
	map_for_flood_fill = create_map_for_flood_fill(map, longest_line_size, amount_of_lines);
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map_for_flood_fill[i][j] && ((map_for_flood_fill[i][j] != 'S') && \
		(map_for_flood_fill[i][j] != 'N') && (map_for_flood_fill[i][j] != 'W') && (map_for_flood_fill[i][j] != 'E')))
			j++;
		if (((map_for_flood_fill[i][j] == 'S') || \
		(map_for_flood_fill[i][j] == 'N') || (map_for_flood_fill[i][j] == 'W') || (map_for_flood_fill[i][j] == 'E')))
			flood_fill(i, j, map_for_flood_fill);
		i++;
	}
	if (!check_if_closed(map_for_flood_fill))
		return (FALSE);
	int a = 0;
	while (map_for_flood_fill[a])
		printf("%s\n", map_for_flood_fill[a++]);
	return (TRUE);
}

void	flood_fill(int x, int y, char **map)
{
	if ((map[x][y] != '0' && map[x][y] != 'S' && map[x][y] != 'W' && map[x][y] != 'N' && map[x][y] != 'E') || \
	map[x + 1][y] == '*' || map[x][y + 1] == '*' || map[x - 1][y] == '*' || map[x][y - 1] == '*' || map[x][y] == '1')
		return;
    if(map[x][y] != 'F')
		map[x][y] = 'F';

    flood_fill(x+1, y, map);
    flood_fill(x-1, y, map);
    flood_fill(x, y+1, map);
    flood_fill(x, y-1, map);
}
