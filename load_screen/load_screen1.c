/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:23:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/12/15 09:57:58 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int obtener_color(int red, int green, int blue)
{
	return (red << 16) | (green << 8) | blue;
}

void paint_fc(t_main *datos)
{
	int i, j;
	j = 0;
	while (j < SCREENHEIGHT)
	{
		i = 0;
		while (i < SCREENWIDTH)
		{
			if (j < SCREENHEIGHT / 2)
				mlx_pixel_put(datos->mlx, datos->window, i, j, obtener_color(datos->info.c_color[0], datos->info.c_color[1], datos->info.c_color[2]));
			else
				mlx_pixel_put(datos->mlx, datos->window, i, j, obtener_color(datos->info.f_color[0], datos->info.f_color[1], datos->info.f_color[2]));
			i++;
		}
		j++;
	}
}

double max_and_min_angles(double player_angle)
{
	//el angulo del jugador solo puede estar entre 0-360.

	if (player_angle < 0)
		player_angle += 2 * M_PI;
	if (player_angle > 2 * M_PI)
		player_angle -= 2 * M_PI;
	return (player_angle);
}

void	load_screen(t_main *datos)
{
	int	i;

	i = 0;
	paint_fc(datos);
	while (i < SCREENWIDTH)
	{
		datos->pa = max_and_min_angles(datos->pa);
		printf("->%f\n", datos->pa);
		i++;
	}
}
