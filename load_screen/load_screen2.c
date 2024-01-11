/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:16:49 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/11 16:18:29 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	draw_pixel(t_main *data, int x, int y, int color)
{
	char	*pos;

	if (x < SCREENWIDTH && y < SCREENHEIGHT)
	{
		pos = data->addr + (y * 4320 + x * (data->bits_per_pixel / 8));
		*(unsigned int *)pos = color;
	}
}

int	get_pixel(t_texture *t, int x, int y)
{
	char	*pos;

	pos = t->addr + (y * 256 + x * (t->bpp / 8));
	return (*(unsigned int *)pos);
}

void	draw_ray(t_main *datos, t_colision co, int x, int h)
{
	int		j;
	double	scale;

	scale = (double)UNIT / h;
	j = 0;
	while (j < h)
	{
		if (320 - h / 2 + j >= 0 && 320 - h / 2 + j < SCREENHEIGHT)
		{
			if ((co.startx - ((int)co.startx / UNIT * UNIT)) == 0 || \
			(co.startx - ((int)co.startx / UNIT * UNIT)) == 63)
			{
				draw_pixel(datos, x, 320 - h / 2 + j, \
				get_pixel(co.texture, \
				(co.starty - ((int)co.starty / UNIT * UNIT)), (scale * j)));
			}
			else
			{
				draw_pixel(datos, x, 320 - h / 2 + j, \
				get_pixel(co.texture, \
				(co.startx - ((int)co.startx / UNIT * UNIT)), (scale * j)));
			}
		}
		j++;
	}
}
