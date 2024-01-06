/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:16:49 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/06 14:40:14 by mikferna         ###   ########.fr       */
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
			mlx_pixel_put(datos->mlx, datos->window, x, j, obtener_color(co.color[0], co.color[1], co.color[2]));
		j++;
	}
}

//void    draw_pixel(t_main *data, int x, int y, int color)
//{
//    char *pos;
//
//    if (x >= 0 && y >= 0 && x < SCREENWIDTH && y < SCREENHEIGHT)
//    {
//        pos = data->addr + (y * data->size + x * (data->bits_per_pixel / 8));
//        *(unsigned int *)pos = color;
//    }
//}
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
//			if ((c.startx - ((int)c.startx / UNIT * UNIT)) == 0 || \
//			(c.startx - ((int)c.startx / UNIT * UNIT)) == 63)
//				draw_pixel(data, x, SCREENHEIGHT / 2 - h / 2 + i, obtener_color(c.color[0], c.color[1], c.color[2]));
//			else
//				draw_pixel(data, x, SCREENHEIGHT / 2 - h / 2 + i, obtener_color(c.color[0], c.color[1], c.color[2]));
//		}
//		i++;
//	}
//}
