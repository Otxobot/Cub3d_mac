/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:25:25 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 17:32:43 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	init_we_texture(t_main *datos)
{
	int	width;
	int	height;

	if (datos->we_texture == NULL)
		printf("Error, one texture allocation is not correct\n");
	if (check_for_texture(datos->info.we_texture))
		return (1);
	datos->we_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.we_texture, &width, &height);
	datos->we_texture->addr = mlx_get_data_addr(datos->we_texture->img, \
	&datos->we_texture->bpp, &datos->we_texture->size, \
	&datos->we_texture->endian);
	return (0);
}

int	init_ea_texture(t_main *datos)
{
	int	width;
	int	height;

	if (datos->ea_texture == NULL)
		printf("Error, one texture allocation is not correct\n");
	if (check_for_texture(datos->info.ea_texture))
		return (1);
	datos->ea_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.ea_texture, &width, &height);
	datos->ea_texture->addr = mlx_get_data_addr(datos->ea_texture->img, \
	&datos->ea_texture->bpp, &datos->ea_texture->size, \
	&datos->ea_texture->endian);
	return (0);
}
