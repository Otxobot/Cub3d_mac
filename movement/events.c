/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:07:10 by abasante          #+#    #+#             */
/*   Updated: 2024/01/12 10:40:46 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"
#define BASEBOARD	0.25

int	move(char **map, double angle, t_main *game)
{
	double	new_x;
	double	new_y;

	new_x = (game->px + cos(angle) * (UNIT/2));
	new_y = (game->py - sin(angle) * (UNIT/2));
	if (map[(int)floor(game->py) / 64] \
	[(int)floor(((new_x + BASEBOARD) / 64))] == '0' \
	&& map[(int)floor(game->py) / 64]
		[(int)floor(((new_x - BASEBOARD) / 64))] == '0')
		game->px = new_x;
	if (map[(int)floor(((new_y + BASEBOARD) / 64))] \
	[(int)floor(game->px) / 64] == '0' \
	&& map[(int)floor(((new_y - BASEBOARD) / 64))] \
	[(int)floor(game->px) / 64] == '0')
		game->py = new_y;
	return (0);
}

int	move_forward(t_main *game)
{
	return (move(game->info.map, game->pa, game));
}

int	move_left(t_main *game)
{
	return (move(game->info.map, game->pa + M_PI / 2, game));
}

int	move_back(t_main *game)
{
	return (move(game->info.map, game->pa + M_PI, game));
}

int	move_right(t_main *game)
{
	return (move(game->info.map, game->pa - M_PI / 2, game));
}
