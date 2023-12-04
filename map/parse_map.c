/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:41 by abasante          #+#    #+#             */
/*   Updated: 2023/12/04 12:48:48 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

/*CREO que las funciones de antes no permiten que entre elementos pasase un trozo de mapa,
por eso empiezo con un bucle de i < 6 para saltar los elementos y empezar a mirar el mapa
lo digo con bastante certeza pero bueno, lo dejo aqui por que esta por ver aun.*/

int parse_map(char **elements_with_map_maybe)
{
	char **map;
	char **map_without_tabs;

	map = check_for_map(elements_with_map_maybe);
	if (map == NULL)
		return (FALSE);
	else
	{
		map_without_tabs = check_if_map_correct(map);
		if (map_without_tabs == NULL)
		{
			printf("we will keep using map\n");
			if (!check_if_walls_closed(map))
				return (FALSE);
		}
		else
		{
			if (!check_if_walls_closed(map_without_tabs))
				return (FALSE);
		}
		return (TRUE);
	}
}

char  **check_if_map_correct(char **map)
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
		return (map_without_tabs);
	}
	else
	{
		printf("THIS MAP HAS NO TABS ALREADY\n");
		return (NULL);
	}
}
