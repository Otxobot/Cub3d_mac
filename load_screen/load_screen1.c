/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:23:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/12/21 12:24:42 by mikferna         ###   ########.fr       */
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
	int			i = 0;
	double 		fov_angle;

	paint_fc(datos);
	fov_angle = M_PI / 3;
	while (i < 1)
	{
		datos->pa = max_and_min_angles(datos->pa);
		colision(datos->pa, datos->px, datos->py, datos);
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
	return (co_v);

	//calcular colisiones horizontales
	//calcular colisiones verticales
	//comparar distancias
	//pintar paredes
}

t_colision	col_v(double fov_angle, t_main *datos, t_colision *c)
{
	datos = NULL;
	(void)fov_angle;
	return (*c);
	// while (TRUE)
	// {
	// 	c->endx += cos(fov_angle) * 0.1;
    //     c->endy += sin(fov_angle) * 0.1;
	// 	//if ()
	// }
}

t_colision colision_vertical(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;
	
	if (fov_angle == M_PI/2 || fov_angle == (3 * M_PI)/2)
		return (co.dist = __DBL_MAX__, co);
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
	double ya;
	if (fov_angle < M_PI)
	{
		//eso quiere decir que estamos en los cuadrantes de arriba, y que tenemos que ir restando la y. Como la y mas pequeña esta arriba, hay que ir restando.
		ya = fmod(datos->py, 1);
		printf("-->ya:%f\n", ya);
		if (ya == 0)
			ya = 1;
	}
	return(*c);
}

t_colision colision_horizontal(double fov_angle, int px, int py, t_main *datos)
{
	t_colision	co;

	px = 0;
	py = 0;
	if (fov_angle == M_PI || fov_angle == (2 * M_PI))
	{
		return (co.dist = __DBL_MAX__, co);
	}
	col_h(fov_angle, datos, &co);
	// while (TRUE)
	// {
		
	// }
	return (co);
}
