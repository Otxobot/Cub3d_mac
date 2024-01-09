/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:16:49 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/09 14:59:13 by mikferna         ###   ########.fr       */
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

//
//void	draw_ray(t_main *data, t_colision c, int x, int h)
//{
//	int		i;
//	double	scale;
//
//	i = 0;
//	scale = (double)UNIT / h;
//	while (i < h)
//	{
//		if (SCREENHEIGHT / 2 - h / 2 + i >= 0 && SCREENHEIGHT / 2 - h / 2 + i < SCREENHEIGHT)
//		{
//			if ((c.startx - ((int)c.startx / UNIT * UNIT)) == 0 ||
//			(c.startx - ((int)c.startx / UNIT * UNIT)) == 63)
//				draw_pixel(data, x, SCREENHEIGHT / 2 - h / 2 + i, obtener_color(c.color[0], c.color[1], c.color[2]));
//			else
//				draw_pixel(data, x, SCREENHEIGHT / 2 - h / 2 + i, obtener_color(c.color[0], c.color[1], c.color[2]));
//		}
//		i++;
//	}
//}
