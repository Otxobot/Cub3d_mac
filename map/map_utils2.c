/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:22 by abasante          #+#    #+#             */
/*   Updated: 2023/12/05 16:54:18 by abasante         ###   ########.fr       */
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
	int i;
	int j;
	char **map_for_flood_fill;

	map_for_flood_fill = malloc(sizeof(char *) * (amount_of_lines + 3));
	i = 0;
	j = 0;
	while (map[i])
	{
		map_for_flood_fill[j++] = malloc(sizeof(char) * (longest_line_size + 2));
		i++;
	}
	int a;
	int b;
	int x;
	int y;

	a = 0;
	b = 0;
	x = 0;
	y = 0;
	// while (y < longest_line_size)
	// 	map_for_flood_fill[x][y++] = '*';
	//x = 1;
	while (map[a])
	{
		y = 0;
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == ' ' || map[a][b] == '\n')
				map_for_flood_fill[x][y] = '*';
			else
				map_for_flood_fill[x][y] = map[a][b];
			y++;
			if (map[a][b])
				b++;
		}
		if (b < longest_line_size)
		{
			printf("This line is not big enough\n");
			while (y <= longest_line_size)
				map_for_flood_fill[x][y++] = '*';
		}
		a++;
		x++;
	}
	// int e = 0;
	// while (map_for_flood_fill[e])
	// 	printf("%s", map_for_flood_fill[e++]);
	return (map_for_flood_fill);
}
