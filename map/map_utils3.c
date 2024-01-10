/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:52:41 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 16:13:21 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char	**allocate_and_initialize(int longest_line_size, int amount_of_lines, \
char **map_for_flood_fill)
{
	int	i;

	map_for_flood_fill = malloc(sizeof(char *) * (amount_of_lines + 3));
	i = 0;
	while (i < amount_of_lines + 2)
	{
		map_for_flood_fill[i] = malloc(sizeof(char) * (longest_line_size + 2));
		ft_memset(map_for_flood_fill[i], '*', longest_line_size + 2);
		map_for_flood_fill[i][longest_line_size + 1] = '\0';
		i++;
	}
	map_for_flood_fill[i] = NULL;
	return (map_for_flood_fill);
}

void	sorround_border2(char **map_for_flood_fill, int longest_line_size, \
int amount_of_lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_for_flood_fill[i])
	{
		j = 0;
		while (map_for_flood_fill[i][j])
		{
			if (j == longest_line_size + 1)
				map_for_flood_fill[i][j] = '*';
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (map_for_flood_fill[i][j])
	{
		map_for_flood_fill[amount_of_lines + 1][j] = '*';
		j++;
	}
}

void	sorround_border(char **map_for_flood_fill, int longest_line_size, \
int amount_of_lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_for_flood_fill[i][j])
	{
		if (map_for_flood_fill[i][j] == '\n')
			j++;
		else
			map_for_flood_fill[i][j++] = '*';
	}
	i = 0;
	j = 0;
	while (map_for_flood_fill[i])
	{
		if (map_for_flood_fill[i][0])
			map_for_flood_fill[i][0] = '*';
		i++;
	}
	sorround_border2(map_for_flood_fill, longest_line_size, amount_of_lines);
}

void	map_inside_mffl(char **map, char **map_for_flood_fill)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != ' ' && map[x][y] != '\n')
				map_for_flood_fill[x + 1][y + 1] = map[x][y];
			y++;
		}
		x++;
	}
}

int	check_if_closed(char **map, int lls, int aml)
{
	int		i;
	int		j;
	t_size	size;

	size.longest_line_size_h = lls;
	size.amount_of_lines_h = aml;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (if_func(map, i, j, &size))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
