/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:22 by abasante          #+#    #+#             */
/*   Updated: 2023/11/29 19:48:46 by abasante         ###   ########.fr       */
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
	/*1 is a wall and 0 is an open space, In this function I want to use flood fill 
	to check whether there is an opening in the map or not, i would do this by checking if the position I am on has contact with either a space or a tab, this way i would know that
	the map is open. If not, the map would be sorrounded by 1s. I would have to check each positions every direction, up, down, left and right.*/

	int i;	//row
	int j;	//column

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (map[i][j] && (map[i][j + 1] == ' ' || map[i][j + 1] == '\t' || map[i][j - 1] == ' ' || map[i][j - 1] == '\t' || map[i + 1][j] == ' ' || map[i + 1][j] == '\t' || map[i - 1][j] == ' ' || map[i - 1][j] == '\t'))
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
