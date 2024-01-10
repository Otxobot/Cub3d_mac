/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:16:49 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/10 15:16:01 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	get_pixel(t_texture *t, int x, int y)
{
	char	*pos;

	pos = t->addr + (y * t->size + x * (t->bpp / 8));
	return (*(unsigned int *)pos);
}

void	draw_ray(t_main *datos, t_colision co, int x, int h)
{
	int j;
	double scale;

	scale = (double)UNIT / h;
	j = 0;
	while (j < h)
	{
		if (320 - h / 2 + j >= 0 && 320 - h / 2 + j < SCREENHEIGHT)
		{
			if ((co.startx - ((int)co.startx / UNIT * UNIT)) == 0 || (co.startx - ((int)co.startx / UNIT * UNIT)) == 63)
				mlx_pixel_put(datos->mlx, datos->window, x, 320 - h / 2 + j, get_pixel(co.texture, (co.starty - ((int)co.starty / UNIT * UNIT)), (scale * j)));
			else
				mlx_pixel_put(datos->mlx, datos->window, x, 320 - h / 2 + j, get_pixel(co.texture, (co.startx - ((int)co.startx / UNIT * UNIT)), (scale * j)));
		}
		j++;
	}
}
