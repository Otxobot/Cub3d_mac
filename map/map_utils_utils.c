/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:43:23 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 16:12:55 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char	**double_pointer_map(char **map_with_tabs)
{
	int		i;
	char	**map_without_tabs;

	i = 0;
	while (map_with_tabs[i])
		i++;
	map_without_tabs = malloc(sizeof(char *) * (i + 1));
	return (map_without_tabs);
}

void	haz_peque(char **map_without_tabs, int a, int *c)
{
	map_without_tabs[a][*c] = ' ';
	map_without_tabs[a][*c + 1] = ' ';
	map_without_tabs[a][*c + 2] = ' ';
	map_without_tabs[a][*c + 3] = ' ';
	*c += 3;
}

int	check_characters(char **map, int a, int b, int player_is_there)
{
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == '1' || map[a][b] == '0' \
			|| map[a][b] == 'N' || map[a][b] == 'S' \
			|| map[a][b] == 'E' || map[a][b] == 'W' \
			|| map[a][b] == '	' || map[a][b] == ' ' || map[a][b] == '\n')
			{
				if (map[a][b] == 'N' || map[a][b] == 'S' || \
				map[a][b] == 'E' || map[a][b] == 'W')
					player_is_there += 1;
				b++;
			}
			else
				return (FALSE);
		}
		a++;
	}
	if (player_is_there > 1 || player_is_there < 1)
		return (FALSE);
	return (TRUE);
}

char	**get_to_map(char **elements_with_map, int *ph)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	while (i < 6)
		i++;
	while (empty_line(elements_with_map[i]))
		i++;
	*ph = i;
	while (elements_with_map[i])
	{
		j++;
		i++;
	}
	map = malloc(sizeof(char *) * (j + 1));
	return (map);
}

int	if_func(char **map, int i, int j, t_size *size)
{
	if (map[i][j] == '*' &&
	((i + 1 < size->amount_of_lines_h && map[i + 1][j] \
	&& map[i + 1][j] != '*' && map[i + 1][j] != '1') ||
	(i - 1 >= 0 && map[i - 1][j] && map[i - 1][j] != '*' \
	&& map[i - 1][j] != '1') ||
	(j + 1 < size->longest_line_size_h && map[i][j + 1] \
	&& map[i][j + 1] != '*' && map[i][j + 1] != '1') ||
	(j - 1 >= 0 && map[i][j - 1] && map[i][j - 1] != '*' \
	&& map[i][j - 1] != '1')))
	{
		return (1);
	}
	return (0);
}
