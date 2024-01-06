/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:07:10 by abasante          #+#    #+#             */
/*   Updated: 2024/01/06 14:54:33 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"
# define BASEBOARD			0.25

int	move(char **map, double angle, t_main *game)
{
	double	new_x;
	double	new_y;

	//printf("->game->px %f\n", game->px);
	//printf("->game->py %f\n", game->py);
	new_x = (game->px + cos(angle) * MOVE_SPEED) / UNIT;
	new_y = (game->py - sin(angle) * MOVE_SPEED) / UNIT;
	//printf("new_x-> %f\n", new_x);
	//printf("new_y-> %f\n", new_y);
	//printf("%c\n", map[(int)floor(game->py) / 64][(int)floor((new_x + BASEBOARD))]);
	//printf("%c\n", map[(int)floor(game->py) / 64][(int)floor((new_x - BASEBOARD))]);
	if (map[(int)floor(game->py) / 64][(int)floor((new_x + BASEBOARD))] == '0' &&
		map[(int)floor(game->py) / 64][(int)floor((new_x - BASEBOARD))] == '0')
		game->px = new_x;
	if (map[(int)floor((new_y + BASEBOARD))][(int)floor(game->px) / 64] == '0' &&
		map[(int)floor((new_y - BASEBOARD))][(int)floor(game->px) / 64] == '0')
		game->py = new_y;
	//printf("-> %f\n", game->px);
	//printf("-> %f\n", game->py);
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