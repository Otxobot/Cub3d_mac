/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:32:25 by abasante          #+#    #+#             */
/*   Updated: 2023/11/28 18:34:18 by abasante         ###   ########.fr       */
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

int check_how_many_tabs(char **map)
{
	int tab_count;
	int a;
	int b;

	tab_count = 0;
	a = 0;
	b = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			if (map[a][b] == 9)
				tab_count++;
			b++;	
		}
		a++;
	}
	return (tab_count);
}

int	check_how_many_tabs_in_a_line(char *line)
{
	int tab_count;
	int i;
	
	tab_count = 0;
	i = 0;	
	while (line[i])
	{
		if (line[i] == 9)
			tab_count++;
		i++;
	}
	return (tab_count);
}

char **replace_tabs_with_spaces(char **map_with_tabs)
{
	char	**map_without_tabs;
	int		tabs_in_line;
	int 	i;
	int		a;
	int		b;
	int		c;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	tabs_in_line = 0;
	while (map_with_tabs[i])
	{
		i++;
	}
	map_without_tabs = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map_with_tabs[i])
	{
		tabs_in_line = check_how_many_tabs_in_a_line(map_with_tabs[i]);
		if (tabs_in_line > 0)
		{
			map_without_tabs[a] = malloc(sizeof(char) * (ft_strlen(map_with_tabs[i]) + (tabs_in_line*3) + 1));
			while (map_with_tabs[i][b])
			{
				if (map_with_tabs[i][b] != 9)
					map_without_tabs[a][c] = map_with_tabs[i][b];
				else
				{
					map_without_tabs[a][c] = ' ';
					map_without_tabs[a][c+1] = ' ';
					map_without_tabs[a][c+2] = ' ';
					map_without_tabs[a][c+3] = ' ';
					c += 3;
				}
				c++;
				b++;	
			}
			map_without_tabs[a][c] = '\0';
			c = 0;
			b = 0;
		}
		else
			map_without_tabs[a] = ft_strdup(map_with_tabs[i]);
		i++;
		a++;
	}
	map_without_tabs[a] = NULL;
	return (map_without_tabs);
}
