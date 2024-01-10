/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:48:48 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 15:51:10 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	obtener_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

double	max_and_min_angles(double player_angle)
{
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
