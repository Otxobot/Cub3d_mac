/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:41 by abasante          #+#    #+#             */
/*   Updated: 2023/12/12 10:18:11 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int parse_map(char **elements_with_map_maybe)
{
	char **map;
	char **map_without_tabs;

	map = check_for_map(elements_with_map_maybe);
	if (map == NULL)
		return (FALSE);
	if (!check_characters(map))
		return (free(map), FALSE);
	else
	{
		map_without_tabs = check_if_map_correct(map);
		if (map_without_tabs == NULL)
		{
			if (!check_if_walls_closed(map))
				return (free(map), FALSE);
			return (TRUE);
		}
		else
		{
			if (!check_if_walls_closed(map_without_tabs))
				return (free(map_without_tabs), FALSE);
			return (TRUE);
		}
		return (ft_double_free(map), TRUE);
	}
}

char  **check_if_map_correct(char **map)
{
	int		tab_count;
	char	**map_without_tabs;

	tab_count = 0;
	tab_count = check_how_many_tabs(map);
	if (tab_count > 0)
	{
		map_without_tabs = replace_tabs_with_spaces(map);
		return (map_without_tabs);
	}
	else
		return (NULL);
}

char **set_null_terminator(char **map)
{
	int a = 0;
	int b = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == '\n')
				map[a][b] = '\0';
			b++;
		}
		a++;
	}
	return (map);
}
