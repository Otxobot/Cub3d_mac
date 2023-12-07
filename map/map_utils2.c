/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:22 by abasante          #+#    #+#             */
/*   Updated: 2023/12/07 11:12:50 by abasante         ###   ########.fr       */
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
	// int a = 0;
	// while (map[a])
	// 	printf("%s", map[a++]);
	// printf("\n====================================================\n\n");
	int i;
	int j;
	char **map_for_flood_fill;

	map_for_flood_fill = malloc(sizeof(char *) * (amount_of_lines + 2));
	i = 0;
	j = 0;
	while (map[i])
	{
		map_for_flood_fill[i] = malloc(sizeof(char) * (longest_line_size + 3));
		ft_memset(map_for_flood_fill[i], '$', longest_line_size + 3);
		i++;
	}
	// i = 0;
	// j = 0;
	// while (map_for_flood_fill[i])
	// {
	// 	j = 0;
	// 	while (map_for_flood_fill[i][j])
	// 	{
	// 		if (j == longest_line_size + 3)
	// 			map_for_flood_fill[i][j] = '\0';
	// 		if (j == longest_line_size + 2)
	// 			map_for_flood_fill[i][j] = '\n';
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// while (map_for_flood_fill[i])
	// 	printf("%s", map_for_flood_fill[i++]);
	// i = 0;
	// j = 0;
	// while (map_for_flood_fill[0][j])
	// 	map_for_flood_fill[0][j++] = '*';
	// map_for_flood_fill[0][j - 1] = '\n';
	// printf("%s", map_for_flood_fill[i]);
	// i = 1;
	// j = 0;
	// while (map_for_flood_fill[i])
	// {
	// 	j = 0;
	// 	while (map_for_flood_fill[i][j])
	// 	{
	// 		if (j == 0)
	// 			map_for_flood_fill[i][j] = '*';
	// 		else if (j == longest_line_size + 1)
	// 			map_for_flood_fill[i][j] = '*';
	// 		else
	// 			map_for_flood_fill[i][j] = map[i][j];
	// 		j++;
	// 	}
	// 	i++;
	// }
	// j = 0;
	// while (map_for_flood_fill[amount_of_lines + 2][j])
	// 	map_for_flood_fill[amount_of_lines + 2][j++] = '*';
	// map_for_flood_fill[amount_of_lines + 2][j - 1] = '\n';
	// printf("\n====================================================\n\n");
	// i = 0;
	// while (map_for_flood_fill[i])
	// 	printf("%s", map_for_flood_fill[i++]);
	// int a;
	// int b;
	// int x;
	// int y;

	// a = 0;
	// b = 0;
	// x = 0;
	// y = 0;
	// while (map[a])
	// {
	// 	y = 0;
	// 	b = 0;
	// 	while (map[a][b])
	// 	{
	// 		if (map[a][b] == ' ' || map[a][b] == '\n')
	// 			map_for_flood_fill[x][y] = '*';
	// 		else
	// 			map_for_flood_fill[x][y] = map[a][b];
	// 		y++;
	// 		if (map[a][b])
	// 			b++;
	// 	}
	// 	if (b < longest_line_size)
	// 	{
	// 		printf("This line is not big enough\n");
	// 		while (y <= longest_line_size)
	// 			map_for_flood_fill[x][y++] = '*';
	// 	}
	// 	a++;
	// 	x++;
	// }
	// int e = 0;
	// while (map_for_flood_fill[e])
	// 	printf("%s", map_for_flood_fill[e++]);
	return (map_for_flood_fill);
}
