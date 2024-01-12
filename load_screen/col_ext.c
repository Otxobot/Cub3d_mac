/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:06:36 by abasante          #+#    #+#             */
/*   Updated: 2024/01/12 10:06:52 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

t_colision	texture_assignation(double fov_angle, t_main *datos, \
t_colision *ch, t_colision *cv)
{
	if (ch->dist < cv->dist)
	{
		if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
			ch->texture = datos->we_texture;
		else
			ch->texture = datos->ea_texture;
		ch->dist = ch->dist * cos(fabs(fov_angle - datos->pa));
		return (*ch);
	}
	else
	{
		if (fov_angle < M_PI)
			cv->texture = datos->no_texture;
		else
			cv->texture = datos->so_texture;
		cv->dist = cv->dist * cos(fabs(fov_angle - datos->pa));
		return (*cv);
	}
}

int	calc_h(double ra, int px, int py, t_colision *c)
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
		c->starty = py - (fabs(c->startx - px) * tan(relative_angle(ra)));
		c->endy = -fabs(c->endx * tan(relative_angle(ra)));
	}
	else
	{
		c->starty = py + (fabs(c->startx - px) * tan(relative_angle(ra)));
		c->endy = fabs(c->endx * tan(relative_angle(ra)));
	}
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
		c->startx--;
	return (0);
}

int	calc_v(double ra, int px, int py, t_colision *c)
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
		c->startx = px + (fabs(c->starty - py) / tan(relative_angle(ra)));
		c->endx = fabs(c->endy / tan(relative_angle(ra)));
	}
	else
	{
		c->startx = px - (fabs(c->starty - py) / tan(relative_angle(ra)));
		c->endx = -fabs(c->endy / tan(relative_angle(ra)));
	}
	if (ra < M_PI)
		c->starty--;
	return (0);
}
