/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_walls_closed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:07:32 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 16:13:01 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_if_walls_closed(char **map, int i)
{
	char	**map_for_flood_fill;
	int		j;

	map_for_flood_fill = create_map_for_flood_fill \
	(map, calc_longest_line(map), calc_amount_of_lines(map));
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map_for_flood_fill[i][j] && \
		((map_for_flood_fill[i][j] != 'S') && \
		(map_for_flood_fill[i][j] != 'N') && \
		(map_for_flood_fill[i][j] != 'W') && (map_for_flood_fill[i][j] != 'E')))
			j++;
		if (((map_for_flood_fill[i][j] == 'S') || \
		(map_for_flood_fill[i][j] == 'N') || (map_for_flood_fill[i][j] == 'W') \
		|| (map_for_flood_fill[i][j] == 'E')))
			flood_fill(i, j, map_for_flood_fill);
		i++;
	}
	if (!check_if_closed(map_for_flood_fill, \
	calc_longest_line(map), calc_amount_of_lines(map)))
		return (FALSE);
	return (TRUE);
}

void	flood_fill(int x, int y, char **map)
{
	if ((map[x][y] != '0' && map[x][y] != 'S' && map[x][y] != 'W' \
	&& map[x][y] != 'N' && map[x][y] != 'E') || \
	map[x + 1][y] == '*' || map[x][y + 1] == '*' || map[x - 1][y] == '*' \
	|| map[x][y - 1] == '*' || map[x][y] == '1')
		return ;
	if (map[x][y] != 'F')
		map[x][y] = 'F';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}
