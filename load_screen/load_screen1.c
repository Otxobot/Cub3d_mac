/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:23:23 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/06 13:32:33 by mikferna         ###   ########.fr       */
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

double	distance(double px, double py, double cx, double cy)
{
	return (sqrt(pow(fabs(px - cx), 2) + pow(fabs(py - cy), 2)));
}

int	leave_map(t_main *datos, t_colision	*c)
{
	int	line_len;

	if (c->starty < 0 || c->starty > 7 - 1)
		return (1);
	line_len = (int)ft_strlen(datos->info.map[(int)c->starty]);
	if (c->startx < 0 || c->startx > line_len - 1)
		return (1);
	return (0);
}

void	load_screen(t_main *datos)
{
	int			i = 540;
	double 		fov_angle;
	double		angle;
	t_colision	co;

	paint_fc(datos);
	fov_angle = M_PI / 2;
	while (i < 541)
	{
		datos->pa = max_and_min_angles(datos->pa);
		angle = max_and_min_angles(datos->pa + (fov_angle / 2) - (fov_angle / SCREENWIDTH * i));
		co = colision(angle, datos->px, datos->py, datos);
		//printf  ("co.dist = %f\n", co.dist);
		draw_ray(datos, co, i, (1 / co.dist) * ((SCREENWIDTH / 2) / tan(fov_angle / 2)));
		i++;
	}
}

t_colision	colision(double fov_angle, double px, double py, t_main *datos)
{
	t_colision co_v;
	t_colision co_h;

	printf("px = %f\n", px);
	printf("py = %f\n", py);
	co_h = colision_horizontal(fov_angle, px, py, datos);
	co_v = colision_vertical(fov_angle, px, py, datos);
	//printf ("co_h.dist = %f\n", co_h.dist);
	//printf ("co_v.dist = %f\n", co_v.dist);
	if (co_h.dist < co_v.dist)
	{
		if (fov_angle < M_PI)
		{
			co_h.color[0] = 0;
			co_h.color[1] = 255;
			co_h.color[2] = 0;
		}
		else
		{
			co_h.color[0] = 0;
			co_h.color[1] = 155;
			co_h.color[2] = 5;
		}
		//printf ("co_h\n");
		co_h.dist = co_h.dist * cos(fabs(fov_angle - datos->pa));
		return (co_h);
	}
	else
	{
		if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
		{
			co_v.color[0] = 0;
			co_v.color[1] = 120;
			co_v.color[2] = 150;
		}
		else
		{
			co_v.color[0] = 0;
			co_v.color[1] = 205;
			co_v.color[2] = 255;
		}
		//printf ("co_v\n");
		co_v.dist = co_v.dist * cos(fabs(fov_angle - datos->pa));
		return (co_v);
	}
	//pintar paredes
}

int	col_v(double fov_angle, double px, double py, t_colision *c)
{
	(void)py;
	if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
	{
		c->startx = fmod(px, 1) * -1;
		//c->startx = px / 1 * 1;
		c->endx = -1;
	}
	else
	{
		c->startx = 1 - fmod(px, 1);
		//c->startx = px / 1 * 1 + 1;
		c->endx = 1;
	}
	//if (fov_angle < M_PI)
	//{
	//	c->starty = py - (fabs(c->startx - px) * tan(normalize(fov_angle)));
	//	c->endy = -fabs(c->endx * tan(normalize(fov_angle)));
	//}
	//else
	//{
	//	c->starty = py + (fabs(c->startx - px) * tan(normalize(fov_angle)));
	//	c->endy = fabs(c->endx * tan(normalize(fov_angle)));
	//}
	if (fov_angle < M_PI)
	{
		c->starty = -fabs(c->startx / tan(normalize(M_PI / 2 - fov_angle)));
		c->endy = -fabs(c->endx / tan(normalize(M_PI / 2 - fov_angle)));
	}
	else
	{
		c->starty = fabs(c->startx / tan(normalize(M_PI / 2 - fov_angle)));
		c->endy = fabs(c->endx / tan(normalize(M_PI / 2 - fov_angle)));
	}
	//if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
	//	c->startx--;
	return(0);
}

int	col_h(double fov_angle, double px, double py, t_colision *c)
{
	(void)px;
	if (fov_angle < M_PI)
	{
		c->starty = fmod(py, 1) * -1;
		//c->starty = py / 1 * 1;
		c->endy = -1;
	}
	else
	{
		c->starty = 1 - fmod(py, 1);
		//c->starty = py / 1 * 1 + 1;
		c->endy = 1;
	}
	//if (fov_angle < M_PI / 2 || fov_angle > 3 * M_PI / 2)
	//{
	//	c->startx = px + (fabs(c->starty - py) / tan(normalize(fov_angle)));
	//	c->endx = fabs(c->endy / tan(normalize(fov_angle)));
	//}
	//else
	//{
	//	c->startx = px - (fabs(c->starty - py) / tan(normalize(fov_angle)));
	//	c->endx = -fabs(c->endy / tan(normalize(fov_angle)));
	//}
	if (fov_angle < M_PI / 2 || fov_angle > 3 * M_PI / 2)
	{
		c->startx = fabs(c->starty / (cos(normalize(M_PI / 2 - fov_angle)) / sin(normalize(M_PI / 2 - fov_angle))));
		c->endx = fabs(c->endy / (cos(normalize(M_PI / 2 - fov_angle)) / sin(normalize(M_PI / 2 - fov_angle))));
	}
	else
	{
		c->startx = -fabs(c->starty / (cos(normalize(M_PI / 2 - fov_angle)) / sin(normalize(M_PI / 2 - fov_angle))));
		c->endx = -fabs(c->endy / (cos(normalize(M_PI / 2 - fov_angle)) / sin(normalize(M_PI / 2 - fov_angle))));
	}
	//printf("c->startx = %f\n", c->startx);
	//printf("c->endx = %f\n", c->endx);
	//printf("c->starty = %f\n", c->starty);
	//printf("c->endy = %f\n", c->endy);
	//if (fov_angle < M_PI)
	//	c->starty--;
	return(0);
}

t_colision colision_vertical(double fov_angle, double px, double py, t_main *datos)
{
	t_colision	co;
	//int			times;

	if (fov_angle == M_PI / 2 || fov_angle == 3 * M_PI / 2)
		return (co.dist = __DBL_MAX__, co);
	col_v(fov_angle, px, py, &co);
	co.startx += px;
	co.starty += py;
	//times = 0;
	while (1)
	{
		if (leave_map(datos, &co) == 1)
		{
			printf("====================================\n");
			printf("v\n");
			printf("co.startx = %f\n", co.startx);
			printf("co.starty = %f\n", co.starty);
			printf("====================================\n");
			printf("salio del mapa\n");
			return (co.dist = __DBL_MAX__, co);
		}
		if (datos->info.map[(int)co.starty][(int)co.startx] == '1')
		{
			printf("====================================\n");
			printf("v\n");
			printf("co.startx = %f\n", co.startx);
			printf("co.starty = %f\n", co.starty);
			printf("datos->info.map[%d][%d] = %c\n", (int)co.starty, (int)co.startx, datos->info.map[(int)co.starty][(int)co.startx]);
			printf("dist: %f\n", distance(px, py, co.startx, co.starty));
			printf("====================================\n");
			return (co.dist = distance(px, py, co.startx, co.starty), co);
		}
		co.startx += co.endx;
		co.starty += co.endy;
		//times++;
	}
}

t_colision colision_horizontal(double fov_angle, double px, double py, t_main *datos)
{
	t_colision	co;
	//int			times;

	if (fov_angle == M_PI || fov_angle == (2 * M_PI) || fov_angle == 0)
		return (co.dist = __DBL_MAX__, co);
	col_h(fov_angle, px, py, &co);
	co.startx += px;
	co.starty += py;
	//times = 0;
	while (1)
	{
		if (leave_map(datos, &co) == 1)
		{
			printf("====================================\n");
			printf("h\n");
			printf("co.startx = %f\n", co.startx);
			printf("co.starty = %f\n", co.starty);
			printf("====================================\n");
			printf("salio del mapa\n");
			return (co.dist = __DBL_MAX__, co);
		}
		if (datos->info.map[(int)co.starty][(int)co.startx] == '1')
		{
			printf("====================================\n");
			printf("h\n");
			printf("co.startx = %f\n", co.startx);
			printf("co.starty = %f\n", co.starty);
			printf("datos->info.map[%d][%d] = %c\n", (int)co.starty, (int)co.startx, datos->info.map[(int)co.starty][(int)co.startx]);
			printf("dist: %f\n", distance(px, py, co.startx, co.starty) - 1);
			printf("====================================\n");
			return (co.dist = distance(px, py, co.startx, co.starty) - 1, co);
		}
		//printf("co.startx = %f\n", co.startx);
		//printf("co.starty = %f\n", co.starty);
		co.startx += co.endx;
		co.starty += co.endy;
		//times++;a
	}
}
