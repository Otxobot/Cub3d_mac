/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:43:09 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/09 14:53:03 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int obtener_color(int red, int green, int blue)
{
	return (red << 16) | (green << 8) | blue;
}

void paint_fc(t_main *datos)
{
	int i;
	int j;

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

double	normalize(double angle)
{
	if (angle <= M_PI / 2)
		return (angle);
	else if (angle <= M_PI)
		return (M_PI - angle);
	else if (angle <= 3 * M_PI / 2)
		return (angle - M_PI);
	else
		return (2 * M_PI - angle);
}

double	distance(double px, double py, double startx, double cy)
{
	return (sqrt(pow(fabs(px - startx), 2) + pow(fabs(py - cy), 2)));
}

int	leave_map(t_main *data, t_colision	*c)
{
	int	line_len;

	if (c->starty / UNIT < 0 || \
		c->starty / UNIT > calc_amount_of_lines(data->info.map) - 1)
		return (1);
	line_len = (int)ft_strlen(data->info.map[(int)c->starty / UNIT]);
	if ((c->startx / UNIT < 0) || \
		(c->startx / UNIT) > line_len - 1)
		return (1);
	return (0);
}

void	load_screen(t_main *datos)
{
	int			i;
	double 		fov_angle;
	double		angle;
	t_colision	co;

	paint_fc(datos);
	fov_angle = M_PI / 2;
	i = 0;
	
	while (i < SCREENWIDTH)
	{
		datos->pa = max_and_min_angles(datos->pa);
		angle = max_and_min_angles(datos->pa + (fov_angle / 2) - (fov_angle / SCREENWIDTH * i));
		co = colision(angle, datos->px, datos->py, datos);
		draw_ray(datos, co, i, (UNIT / co.dist) * ((SCREENWIDTH / 2) / tan(fov_angle / 2)));
		i++;
	}
}

t_colision	colision(double fov_angle, double px, double py, t_main *datos)
{
	t_colision co_v;
	t_colision co_h;

	co_h = col_h(fov_angle, px, py, datos);
	co_v = col_v(fov_angle, px, py, datos);
	if (co_h.dist < co_v.dist)
	{
		if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
		{
			co_h.texture = datos->we_texture;
		}
		else
		{
			co_h.texture = datos->ea_texture;
		}
		co_h.color[0] = 255;
		co_h.color[1] = 0;
		co_h.color[2] = 0;
		co_h.dist = co_h.dist * cos(fabs(fov_angle - datos->pa));
		return (co_h);
	}
	else
	{
		if (fov_angle < M_PI)
		{
			co_v.texture = datos->no_texture;
		}
		else
		{
			co_v.texture = datos->so_texture;
		}
		co_v.color[0] = 0;
		co_v.color[1] = 255;
		co_v.color[2] = 0;
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
		if (data->info.map[(int)(c.starty / UNIT)][(int)(c.startx / UNIT)] == '1')
			return (c.dist = distance(data->px, data->py, c.startx, c.starty), c);
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
		if (data->info.map[(int)(c.starty / UNIT)][(int)(c.startx / UNIT)] == '1')
			return (c.dist = distance(data->px, data->py, c.startx, c.starty), c);
		c.startx += c.endx;
		c.starty += c.endy;
	}
}