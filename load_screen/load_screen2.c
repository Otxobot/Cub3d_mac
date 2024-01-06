/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:16:49 by mikferna          #+#    #+#             */
/*   Updated: 2023/12/28 13:48:48 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	draw_ray(t_main *datos, t_colision co, int x, int h)
{
	int j;
	(void)co;

	j = 0;
	while (j < SCREENWIDTH)
	{
		if (j > (SCREENHEIGHT / 2) - (h / 2) && j < (SCREENHEIGHT / 2) + (h / 2))
			mlx_pixel_put(datos->mlx, datos->window, x, j, obtener_color(0, 224, 255));
		j++;
	}
}
