/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:41 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 14:01:47 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	parse_map(char **elements_with_map_maybe, t_info *info)
{
	char	**map;
	int		tabs_or_not;

	map = check_for_map(elements_with_map_maybe);
	if (map == NULL)
		return (FALSE);
	if (!check_characters(map, 0, 0, 0))
		return (ft_double_free(map), FALSE);
	else
	{
		tabs_or_not = check_if_map_correct(map);
		if (tabs_or_not == 1)
			return (FALSE);
		else
		{
			if (!check_if_walls_closed(map, 0))
				return (ft_double_free(map), FALSE);
			return (player_and_map_in_info(map, info), TRUE);
		}
		return (ft_double_free(map), TRUE);
	}
}

int	check_if_map_correct(char **map)
{
	int		tab_count;

	tab_count = 0;
	tab_count = check_how_many_tabs(map);
	if (tab_count > 0)
	{
		ft_double_free(map);
		return (1);
	}
	else
		return (0);
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
