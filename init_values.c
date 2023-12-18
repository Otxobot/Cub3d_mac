/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:49:31 by mikferna          #+#    #+#             */
/*   Updated: 2023/12/14 16:14:24 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	p_ori(t_main *datos)
{
	if (datos->info.player == 'N')
		datos->pa = 1 * (M_PI / 2);
	else if (datos->info.player == 'S')
		datos->pa = 3 * (M_PI / 2);
	else if (datos->info.player == 'E')
		datos->pa = 0 * (M_PI / 2);
	else if (datos->info.player == 'W')
		datos->pa = 2 * (M_PI / 2);
}

void	init_values(t_main *datos)
{
	int	j;
	int	i;

	j = -1;
	while (datos->info.map[++j])
	{
		i = -1;
		while (datos->info.map[j][++i])
		{
			if (datos->info.map[j][i] == datos->info.player)
			{
				datos->px = i + 0.5;
				datos->py = j + 0.5;
			}
		}
	}
	p_ori(datos);
	printf("->%f\n", datos->pa);
}