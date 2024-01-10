/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:04:05 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 12:17:13 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_mlx(t_main *datos)
{
	datos->mlx = mlx_init();
	datos->addr = mlx_new_window(datos->mlx, SCREENWIDTH, \
		SCREENHEIGHT, "cub3d");
	datos->image = mlx_new_image(datos->mlx, SCREENWIDTH, SCREENHEIGHT);
	datos->addr = mlx_get_data_addr(datos->image, \
	&datos->bits_per_pixel, &datos->size, &datos->endian);
}
