/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:41 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 14:20:35 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	parse_map(char **elements_with_map_maybe, t_info *info)
{
	char	**map;
	char	**map_without_tabs;

	map = check_for_map(elements_with_map_maybe);
	if (map == NULL)
		return (FALSE);
	if (!check_characters(map, 0, 0, 0))
		return (ft_double_free(map), FALSE);
	else
	{
		map_without_tabs = check_if_map_correct(map);
		if (map_without_tabs == NULL)
		{
			if (!check_if_walls_closed(map, 0))
				return (ft_double_free(map), FALSE);
			return (player_and_map_in_info(map, info), TRUE);
		}
		else
		{
			if (!check_if_walls_closed(map_without_tabs, 0))
				return (ft_double_free(map_without_tabs), FALSE);
			return (player_and_map_in_info(map_without_tabs, info), TRUE);
		}
		return (ft_double_free(map), TRUE);
	}
}

char	**check_if_map_correct(char **map)
{
	int		tab_count;
	char	**map_without_tabs;

	tab_count = 0;
	tab_count = check_how_many_tabs(map);
	if (tab_count > 0)
	{
		map_without_tabs = replace_tabs_with_spaces(map, 0, 0, 0);
		ft_double_free(map);
		return (map_without_tabs);
	}
	else
		return (NULL);
}

void	player_and_map_in_info(char **map, t_info *info)
{
	int		i;
	int		j;
	char	player;

	player = '\0';
	i = 0;
	j = 0;
	info->map = map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'W' || \
			map[i][j] == 'E' || map[i][j] == 'N')
			{
				player = map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
	info->player = player;
}
