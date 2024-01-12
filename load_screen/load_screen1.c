/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:43:09 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/12 10:06:17 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	load_screen(t_main *datos)
{
	int			i;
	double		fov_angle;
	double		angle;
	t_colision	co;

	fov_angle = M_PI / 3;
	i = 0;
	paint_fc(datos);
	while (i < SCREENWIDTH)
	{
		datos->pa = max_and_min_angles(datos->pa);
		angle = max_and_min_angles(datos->pa + (fov_angle / 2) - \
		(fov_angle / SCREENWIDTH * i));
		co = colision(angle, datos->px, datos->py, datos);
		draw_ray(datos, co, i, (UNIT / co.dist) * ((SCREENWIDTH / 2) / \
		tan(fov_angle / 2)));
		i++;
	}
	mlx_put_image_to_window(datos->mlx, datos->window, datos->image, 0, 0);
	return (0);
}

t_colision	colision(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	cv;
	t_colision	ch;

	ch = col_h(fov_angle, px, py, datos);
	cv = col_v(fov_angle, px, py, datos);
	return (texture_assignation(fov_angle, datos, &ch, &cv));
}

t_colision	col_v(double ra, int px, int py, t_main *data)
{
	t_colision	c;

	if (ra == (2 * M_PI) || ra == M_PI || ra == 0)
		return (c.dist = __DBL_MAX__, c);
	calc_v(ra, px, py, &c);
	while (1)
	{
		if (check_pos(data, &c) == 1)
			return (c.dist = __DBL_MAX__, c);
		if (data->info.map[(int)(c.starty / UNIT)] \
		[(int)(c.startx / UNIT)] == '1')
		{
			return (c.dist = pitagoras(data->px, data->py, \
			c.startx, c.starty), c);
		}
		c.startx += c.endx;
		c.starty += c.endy;
	}
}

t_colision	col_h(double ra, int px, int py, t_main *data)
{
	t_colision	c;

	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (c.dist = __DBL_MAX__, c);
	calc_h(ra, px, py, &c);
	while (1)
	{
		if (check_pos(data, &c) == 1)
			return (c.dist = __DBL_MAX__, c);
		if (data->info.map[(int)(c.starty / UNIT)] \
		[(int)(c.startx / UNIT)] == '1')
		{
			return (c.dist = pitagoras(data->px, data->py, \
			c.startx, c.starty), c);
		}
		c.startx += c.endx;
		c.starty += c.endy;
	}
}
