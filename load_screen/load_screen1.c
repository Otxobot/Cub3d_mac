/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:23:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/12/26 11:22:15 by mikferna         ###   ########.fr       */
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

void	load_screen(t_main *datos)
{
	int			i = 540;
	double 		fov_angle;
	double		angle;
	t_colision	co;

	paint_fc(datos);
	fov_angle = M_PI / 3;
	while (i < 541)
	{
		datos->pa = max_and_min_angles(datos->pa);
		angle = max_and_min_angles(datos->pa + (fov_angle / 2) - (fov_angle / SCREENWIDTH * i));
		co = colision(datos->pa, datos->px, datos->py, datos);
		printf ("distancia: %f\n", co.dist);
		draw_ray(datos, co, i, co.dist / 32 * ((SCREENWIDTH / 2) / tan(fov_angle / 2)));
		//printf ("distancia: %f\n", co.dist);
		i++;
	}
}

t_colision	colision(double fov_angle, int px, int py, t_main *datos)
{
	t_colision co_v;
	t_colision co_h;

	co_h = colision_horizontal(fov_angle, px, py, datos);
	co_v = colision_vertical(fov_angle, px, py, datos);
	printf("co_h: %f\n", co_h.dist);
	printf("co_v: %f\n", co_v.dist);
	if (co_h.dist < co_v.dist)
		return (co_h);
	else
		return (co_v);
	//pintar paredes
}

t_colision	col_v(double fov_angle, t_main *datos, t_colision *c)
{
	if (fov_angle > M_PI / 2 && fov_angle < (3 * M_PI) / 2)
		c->startx = fmod(datos->px, 1);
	else
		c->startx = 1 - fmod(datos->px, 1);
	if (fov_angle < M_PI)
		c->startx = fmod(datos->py, 1);
	else
		c->startx = 1 - fmod(datos->py, 1);
	if (c->startx == 0)
		c->startx = 1;
	c->first_impact = fabs(c->startx / (cos(fabs(fov_angle - M_PI))));
	c->rest_of_impacts = fabs(1 / (cos(fabs(fov_angle - M_PI))));
	c->endx = 1;
	c->endy = 1;
	return(*c);
}

t_colision colision_vertical(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;
	int times;

	px = 0;
	py = 0;
	if (fov_angle == M_PI/2 || fov_angle == (3 * M_PI)/2)
		return (co.dist = __DBL_MAX__, co);
	col_v(fov_angle, datos, &co);
	px += co.startx;
	py += co.starty;
	times = 0;
	while (TRUE)
	{
		if (px + 1 > ft_strlen(datos->info.map[py + 1]) || py + 1 > 14 || px + 1 < 0 || py + 1 < 0)
			return (co.dist = __DBL_MAX__, co);
		//puede que este if falle, si no esta colisionando contra una pered pero al comprobar el +1 si, devolveria la posicion incorrecta
		if (datos->info.map[py + 1][px + 1] == '1')
			return (co.dist = co.first_impact + (co.rest_of_impacts * times), co);
		px += co.endx;
		py += co.endy;
		times++;
	}
	return (co);
}

t_colision	col_h(double fov_angle, t_main *datos, t_colision *c)
{
	if (fov_angle < M_PI)
		c->starty = fmod(datos->py, 1);
	else
		c->starty = 1 - fmod(datos->py, 1);
	if (fov_angle > M_PI / 2 && fov_angle < (3 * M_PI) / 2)
		c->startx = fmod(datos->px, 1);
	else
		c->startx = 1 - fmod(datos->px, 1);
	if (c->starty == 0)
		c->starty = 1;
	c->first_impact = fabs(c->starty / (cos(fabs(fov_angle - (M_PI / 2)))));
	c->rest_of_impacts = fabs(1 / (cos(fabs(fov_angle - (M_PI / 2)))));
	c->endx = 1;
	c->endy = 1;
	return(*c);
}

t_colision colision_horizontal(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;
	int times;

	if (fov_angle == M_PI || fov_angle == (2 * M_PI))
		return (co.dist = __DBL_MAX__, co);
	col_h(fov_angle, datos, &co);
	px += co.startx;
	py += co.starty;
	times = 0;
	while (TRUE)
	{
		if (px + 1 > ft_strlen(datos->info.map[py]) || py + 1 > 14 || px + 1 < 0 || py + 1 < 0)
			return (co.dist = __DBL_MAX__, co);
		if (datos->info.map[py + 1][px + 1] == '1')
			return (co.dist = co.first_impact + (co.rest_of_impacts * times), co);
		px += co.endx;
		py += co.endy;
		times++;
	}	
	return (co);
}
