/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:43:09 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/11 16:23:44 by abasante         ###   ########.fr       */
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
	//mlx_put_image_to_window(datos->mlx, datos->window, datos->image, 0, 0);
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
	t_colision	co_v;
	t_colision	co_h;

	co_h = col_h(fov_angle, px, py, datos);
	co_v = col_v(fov_angle, px, py, datos);
	if (co_h.dist < co_v.dist)
	{
		if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
			co_h.texture = datos->we_texture;
		else
			co_h.texture = datos->ea_texture;
		co_h.dist = co_h.dist * cos(fabs(fov_angle - datos->pa));
		return (co_h);
	}
	else
	{
		if (fov_angle < M_PI)
			co_v.texture = datos->no_texture;
		else
			co_v.texture = datos->so_texture;
		co_v.dist = co_v.dist * cos(fabs(fov_angle - datos->pa));
		return (co_v);
	}
}

int	calc_col_v_data(double ra, int px, int py, t_colision *c)
{
	if (ra < M_PI)
	{
		c->starty = py / UNIT * UNIT;
		c->endy = -UNIT;
	}
	else
	{
		c->starty = py / UNIT * UNIT + UNIT;
		c->endy = UNIT;
	}
	if (ra < M_PI / 2 || ra > 3 * M_PI / 2)
	{
		c->startx = px + (fabs(c->starty - py) / tan(normalize(ra)));
		c->endx = fabs(c->endy / tan(normalize(ra)));
	}
	else
	{
		c->startx = px - (fabs(c->starty - py) / tan(normalize(ra)));
		c->endx = -fabs(c->endy / tan(normalize(ra)));
	}
	if (ra < M_PI)
		c->starty--;
	return (0);
}

t_colision	col_v(double ra, int px, int py, t_main *data)
{
	t_colision	c;

	if (ra == (2 * M_PI) || ra == M_PI || ra == 0)
		return (c.dist = 1e30, c);
	calc_col_v_data(ra, px, py, &c);
	while (1)
	{
		if (leave_map(data, &c) == 1)
			return (c.dist = 1e30, c);
		if (data->info.map[(int)(c.starty / UNIT)] \
		[(int)(c.startx / UNIT)] == '1')
		{
			return (c.dist = distance(data->px, data->py, \
			c.startx, c.starty), c);
		}
		c.startx += c.endx;
		c.starty += c.endy;
	}
}

int	calc_col_h_data(double ra, int px, int py, t_colision *c)
{
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
	{
		c->startx = px / UNIT * UNIT;
		c->endx = -UNIT;
	}
	else
	{
		c->startx = px / UNIT * UNIT + UNIT;
		c->endx = UNIT;
	}
	if (ra < M_PI)
	{
		c->starty = py - (fabs(c->startx - px) * tan(normalize(ra)));
		c->endy = -fabs(c->endx * tan(normalize(ra)));
	}
	else
	{
		c->starty = py + (fabs(c->startx - px) * tan(normalize(ra)));
		c->endy = fabs(c->endx * tan(normalize(ra)));
	}
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
		c->startx--;
	return (0);
}

t_colision	col_h(double ra, int px, int py, t_main *data)
{
	t_colision	c;

	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (c.dist = 1e30, c);
	calc_col_h_data(ra, px, py, &c);
	while (1)
	{
		if (leave_map(data, &c) == 1)
			return (c.dist = 1e30, c);
		if (data->info.map[(int)(c.starty / UNIT)] \
		[(int)(c.startx / UNIT)] == '1')
		{
			return (c.dist = distance(data->px, data->py, \
			c.startx, c.starty), c);
		}
		c.startx += c.endx;
		c.starty += c.endy;
	}
}
