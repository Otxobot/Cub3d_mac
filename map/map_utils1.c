/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:32:25 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 12:33:25 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char	**check_for_map(char **elements_with_map)
{
	int		ph;
	int		a;
	char	**map;

	a = 0;
	ph = 0;
	map = get_to_map(elements_with_map, &ph);
	while (elements_with_map[ph])
	{
		if (empty_line(elements_with_map[ph]))
		{
			if (see_if_there_is_no_more_map(&elements_with_map[ph]))
				break ;
			else
			{
				map[a] = NULL;
				return (ft_double_free(map));
			}
		}
		map[a] = ft_strdup(elements_with_map[ph]);
		a++;
		ph++;
	}
	map[a] = NULL;
	return (map);
}

int	check_how_many_tabs(char **map)
{
	int	tab_count;
	int	a;
	int	b;

	tab_count = 0;
	a = 0;
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
	int	tab_count;
	int	i;

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

char	**replace_tabs_with_spaces(char **mwt, int i, int a, int b)
{
	char	**mwot;
	int		t;
	int		c;

	c = 0;
	t = 0;
	mwot = double_pointer_map(mwt);
	while (mwt[i])
	{
		t = check_how_many_tabs_in_a_line(mwt[i]);
		if (t > 0)
		{
			mwot[a] = malloc(sizeof(char) * (ft_strlen(mwt[i]) + (t * 3) + 1));
			while (mwt[i][b])
			{
				if (mwt[i][b] != 9)
					mwot[a][c] = mwt[i][b];
				else
					haz_peque(mwot, a, &c);
				c++;
				b++;
			}
			mwot[a][c] = '\0';
			c = 0;
			b = 0;
		}
		else
			mwot[a] = ft_strdup(mwt[i]);
		i++;
		a++;
	}
	return ((mwot[a] = NULL), mwot);
}
