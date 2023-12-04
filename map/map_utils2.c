/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:22 by abasante          #+#    #+#             */
/*   Updated: 2023/12/04 13:14:16 by abasante         ###   ########.fr       */
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

int check_if_walls_closed(char **map)
{
	int i;	//row
	int j;	//column

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '1' || map[i][j] == '\n'))
		{
			j++;
		}
		if (map[i][j] == '0')
		{
			flood_fill(i, j, '0', '0', map);
			break;
		}
		i++;
	}
	printf("===============CHECKING IF WALLS ARE CLOSED:===============\n");
	return (TRUE);
}

// void	 flood_fill(char **map)
// {
// 	printf("entro al flood_fill\n");
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
	
	
// }

void	flood_fill(int x, int y, int prevC, int newC, char **map)
{
    // Si la posición está fuera de los límites del mapa, retorna
    if(x < 0 || x == '\n' || y < 0 || y == ' ')
        return;

    // Si el valor en la posición no es el valor objetivo, retorna
    if(map[x][y] != prevC)
        return;

    // Cambia el valor en la posición al valor de reemplazo
    map[x][y] = newC;

    // Llama a la función para las posiciones arriba, abajo, a la izquierda y a la derecha
    flood_fill(x+1, y, prevC, newC, map);
    flood_fill(x-1, y, prevC, newC, map);
    flood_fill(x, y+1, prevC, newC, map);
    flood_fill(x, y-1, prevC, newC, map);
}
