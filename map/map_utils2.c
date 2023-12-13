/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:22 by abasante          #+#    #+#             */
/*   Updated: 2023/12/12 10:19:03 by abasante         ###   ########.fr       */
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

int calc_longest_line(char **map)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

int calc_amount_of_lines(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char **create_map_for_flood_fill(char **map, int longest_line_size, int amount_of_lines)
{
	char **map_for_flood_fill;
	map_for_flood_fill = NULL;

	map_for_flood_fill = allocate_and_initialize(longest_line_size, amount_of_lines, map_for_flood_fill);
	sorround_border(map_for_flood_fill, longest_line_size, amount_of_lines);
	map_inside_mffl(map, map_for_flood_fill);
	return (map_for_flood_fill);
}
