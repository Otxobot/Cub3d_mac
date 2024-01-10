/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:16:49 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/10 13:51:10 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	get_pixel(t_texture *t, int x, int y)
{
	char	*pos;

	pos = t->addr + (y * t->size + x * (t->bpp / 8));
	return (*(unsigned int *)pos);
}

void draw_ray(t_main *datos, t_colision co, int x, int h)
{
    int j;
    double scale;

    scale = (double)UNIT / h;
    j = 0;

    int tex_width; // Ancho de la textura
    int tex_height; // Alto de la textura
    
    // Obtener el ancho y alto de la textura desde la imagen cargada en t_texture->img
    // Usando mlx_get_img_size() o la función correspondiente de la librería que maneja las imágenes
    // Esto puede variar dependiendo de la librería específica que maneje la carga de imágenes
    // Supongamos que mlx_get_img_size() es una función de mlx que devuelve las dimensiones de la imagen
    mlx_get_img_size(co.texture->img, &tex_width, &tex_height);

    while (j < h)
    {
        if (320 - h / 2 + j >= 0 && 320 - h / 2 + j < SCREENHEIGHT)
        {
            int tex_x = (co.startx - ((int)co.startx / UNIT * UNIT));
            if (tex_x == 0 || tex_x == 63) {
                int tex_y = co.starty - ((int)co.starty / UNIT * UNIT) + (int)(scale * j);
                if (tex_y >= 0 && tex_y < tex_height) {
                    mlx_pixel_put(datos->mlx, datos->window, x, 320 - h / 2 + j, get_pixel(co.texture, tex_x, tex_y));
                }
            } else {
                int tex_x = co.startx - ((int)co.startx / UNIT * UNIT) + (int)(scale * j);
                if (tex_x >= 0 && tex_x < tex_width) {
                    mlx_pixel_put(datos->mlx, datos->window, x, 320 - h / 2 + j, get_pixel(co.texture, tex_x, co.starty - ((int)co.starty / UNIT * UNIT)));
                }
            }
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
