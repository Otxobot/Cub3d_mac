/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:23:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/12/19 15:54:24 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int obtener_color(int red, int green, int blue)
{
	return (red << 16) | (green << 8) | blue;
}

void paint_fc(t_main *datos)
{
	int i, j;
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
	int			i;
	t_colision	co;
	double 		fov_angle;

	i = 0;
	paint_fc(datos);
	fov_angle = M_PI / 3;
	while (i < 1)
	{
		datos->pa = max_and_min_angles(datos->pa);
		co = colision(datos->pa, datos->px, datos->py, datos);
		//printf ("distancia: %f\n", co.dist);
		i++;
	}
}

t_colision	colision (double fov_angle, int px, int py, t_main *datos)
{
	t_colision co_v;
	//t_colision co_h;

	co_v = colision_vertical(fov_angle, px, py, datos);
	printf ("distancia vertical: %f\n", co_v.dist);
	return (co_v);
	//co_h = colision_horizontal(fov_angle, px, py, datos);

	//calcular colisiones horizontales
	//calcular colisiones verticales
	//comparar distancias
	//pintar paredes
}

t_colision	col_v(double fov_angle, t_main *datos, t_colision *c)
{
	(void)fov_angle;
	(void)datos;
	return (*c);
}

t_colision colision_vertical(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;

	if (fov_angle == M_PI/2 || fov_angle == (3 * M_PI)/2)
	{
		co.dist = __DBL_MAX__;
		return (co);
	}
	co.endx = px;
	co.endy = py;
	col_v(fov_angle, datos, &co);
	while (TRUE)
	{
		co.endx += cos(fov_angle) * 0.1;
        co.endy += sin(fov_angle) * 0.1; 
		if (!datos->info.map[(int)co.endy][(int)co.endx])
			return (co.dist = __DBL_MAX__, co);
		if (datos->info.map[(int)co.endy][(int)co.endx] == '1')
		{
			co.dist = sqrt(pow(co.endx - px, 2) + pow(co.endy - py, 2));
			break;
		}
	}
	return (co);
}

t_colision	col_h(double fov_angle, t_main *datos, t_colision *c)
{
	(void)fov_angle;
	(void)datos;
	return (*c);
	//if (fov_angle > M_PI && fov_angle < 2 * M_PI)
	//{
	//	
	//}
	//else
	//{
	//	
	//}
	//return (*c);
}


//t_colision colision_horizontal(double fov_angle, int px, int py, t_main *datos)
//{
//	t_colision	co;
//}
