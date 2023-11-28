/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:32:25 by abasante          #+#    #+#             */
/*   Updated: 2023/11/28 14:20:42 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char **check_for_map(char **elements_with_map)
{
	int i;
	int j;
	int a;
	int ph;
	char **map;

	j = 0;
	i = 0;
	a = 0;
	while (i < 6)
		i++;
	ph = i;
	while (elements_with_map[i])
	{
		j++;
		i++;
	}
	map = malloc(sizeof(char *) * (j + 1));
	while (elements_with_map[ph])
	{
		map[a] = elements_with_map[ph];
		a++;
		ph++;
	}
	map[a] = NULL;
	return (map);
}

int check_characters(char **map)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == '1' || map[a][b] == '0' \
			|| map[a][b] == 'N' || map[a][b] == 'S' \
			|| map[a][b] == 'E' || map[a][b] == 'W' \
			|| map[a][b] == 32 || map[a][b] == 9 || map[a][b] == '\n')
				b++;
			else
				return (FALSE);
		}
		a++;
	}
	return (TRUE);
}
