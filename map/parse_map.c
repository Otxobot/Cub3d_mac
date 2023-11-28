/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:41 by abasante          #+#    #+#             */
/*   Updated: 2023/11/28 18:12:05 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

	/*CREO que las funciones de antes no permiten que entre elementos pasase un trozo de mapa,
	por eso empiezo con un bucle de i < 6 para saltar los elementos y empezar a mirar el mapa
	lo digo con bastante certeza pero bueno, lo dejo aqui por que esta por ver aun.*/

int parse_map(char **elements_with_map_maybe)
{
	char **map;

	map = check_for_map(elements_with_map_maybe);
	if (map[0] == NULL)
	{
		printf("There is no map\n");
		ft_double_free (map);
		return (FALSE);
	}
	else
	{
		printf("we have a map\nvamos a ver si esta bien...\n");
		if (!check_if_map_correct(map))
			return (FALSE);
		return (TRUE);
	}
}

int check_if_map_correct(char **map)
{
	int		tab_count;
	char	**map_without_tabs;

	tab_count = 0;
	if (!check_characters(map))
		return (FALSE);
	tab_count = check_how_many_tabs(map);
	if (tab_count > 0)
	{
		map_without_tabs = replace_tabs_with_spaces(map);
		int a = 0;
		int b = 0;
		while (map_without_tabs[a] && map_without_tabs[a][b] != '	')
			printf("%s", map_without_tabs[a++]);
	}
	else
		printf("THIS MAP HAS NO TABS ALREADY\n");
	return (TRUE);
}
