/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:23:23 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/03 12:53:09 by mikferna         ###   ########.fr       */
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


int	leave_map(t_main *datos, t_colision	*c)
{
	int	line_len;

	if (c->starty < 0 || c->starty > 14 - 1)
		return (1);
	line_len = (int)ft_strlen(datos->info.map[(int)c->starty]);
	if (c->startx < 0 || c->startx > line_len - 1)
		return (1);
	return (0);
}

void	load_screen(t_main *datos)
{
	int			i = 0;
	double 		fov_angle;
	double		angle;
	t_colision	co;

	paint_fc(datos);
	fov_angle = M_PI / 3;
	while (i < SCREENWIDTH)
	{
		datos->pa = max_and_min_angles(datos->pa);
		angle = max_and_min_angles(datos->pa + (fov_angle / 2) - (fov_angle / SCREENWIDTH * i));
		co = colision(angle, datos->px, datos->py, datos);
		if (i == 540)
			printf("co.dist: %f\n", co.dist);
		draw_ray(datos, co, i, (1 / co.dist) * ((SCREENWIDTH / 2) / tan(fov_angle / 2)));
		i++;
	}
}

t_colision	colision(double fov_angle, int px, int py, t_main *datos)
{
	t_colision co_v;
	t_colision co_h;

	co_h = colision_horizontal(fov_angle, px, py, datos);
	co_v = colision_vertical(fov_angle, px, py, datos);
	if (co_h.dist < co_v.dist)
		return (co_h);
	else
		return (co_v);
	//pintar paredes
}

t_colision	col_v(double fov_angle, int px, int py, t_colision *c)
{
	if (fov_angle >= M_PI / 2 && fov_angle <= (3 * M_PI) / 2)
	{
		c->startx = px + (fmod(px, 1) * -1);
		c->endx = -1;
	}
	else
	{
		c->startx = px + (1 - fmod(px, 1));
		c->endx = 1;
	}
	if (fov_angle < M_PI)
	{
		c->starty = py - (fabs(c->startx - px) * tan(max_and_min_angles(fov_angle)));
		c->endy = -fabs(c->endx * tan(max_and_min_angles(fov_angle)));
	}
	else
	{
		c->starty = py + (fabs(c->startx - px) * tan(max_and_min_angles(fov_angle)));
		c->starty = fabs(c->endx * tan(max_and_min_angles(fov_angle)));
	}
	if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
		c->startx--;
	return(*c);
}

t_colision	col_h(double fov_angle, int px, int py, t_colision *c)
{
	if (fov_angle < M_PI)
	{
		c->starty = py + (fmod(py, 1) * -1);
		c->endy = -1;
	}
	else
	{
		c->starty = py + (1 - fmod(py, 1));
		c->endy = 1;
	}
	if (fov_angle >= M_PI / 2 && fov_angle <= (3 * M_PI / 2))
	{
		c->startx = px + (fabs(c->starty - py) / tan(max_and_min_angles(fov_angle)));
		c->endx = fabs(c->endy / tan(max_and_min_angles(fov_angle)));
	}
	else
	{
		c->startx = px - (fabs(c->starty - py) / tan(max_and_min_angles(fov_angle)));
		c->endx = -fabs(c->endy / tan(max_and_min_angles(fov_angle)));
	}
	if (fov_angle < M_PI)
		c->starty--;
	return(*c);
}

t_colision colision_vertical(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;

	if (fov_angle == M_PI/2 || fov_angle == (3 * M_PI)/2)
		return (co.dist = __DBL_MAX__, co);
	col_v(fov_angle, px, py, &co);
	while (1)
	{
		if (leave_map(datos, &co) == 1)
			return (co.dist = __DBL_MAX__, co);
		else if (datos->info.map[(int)co.starty][(int)co.startx] == '1')
			return (co.dist = sqrt(pow(fabs(px - co.startx), 2) + pow(fabs(py - co.starty), 2)), co);
		co.startx += co.endx;
		co.starty += co.endy;
	}
	return (co.dist = __DBL_MAX__, co);
}

t_colision colision_horizontal(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;

	if (fov_angle == M_PI || fov_angle == (2 * M_PI) || fov_angle == 0)
		return (co.dist = __DBL_MAX__, co);
	col_h(fov_angle, px, py, &co);
	while (1)
	{
		if (leave_map(datos, &co) == 1)
			return (co.dist = __DBL_MAX__, co);
		else if (datos->info.map[(int)co.starty][(int)co.startx] == '1')
			return (co.dist = sqrt(pow(fabs(px - co.startx), 2) + pow(fabs(py - co.starty), 2)), co);
		co.startx += co.endx;
		co.starty += co.endy;
	}
	return (co.dist = __DBL_MAX__, co);
}
