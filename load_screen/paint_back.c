/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:51:42 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 16:19:40 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	paint_fc(t_main *datos)
{
	int	i;
	int	j;

	j = 0;
	while (j < SCREENHEIGHT)
	{
		i = 0;
		while (i < SCREENWIDTH)
		{
			if (j < SCREENHEIGHT / 2)
			{
				draw_pixel(datos, i, j, \
				obtener_color(datos->info.c_color[0], datos->info.c_color[1], \
				datos->info.c_color[2]));
			}
			else
			{
				draw_pixel(datos, i, j, \
				obtener_color(datos->info.f_color[0], datos->info.f_color[1], \
				datos->info.f_color[2]));
			}
			i++;
		}
		j++;
	}
}