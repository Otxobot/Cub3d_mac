/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:25:25 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 12:25:47 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	init_we_texture(t_main *datos)
{
	int	width;
	int	height;
	int	flag;

	flag = 3;
	if (datos->we_texture == NULL)
		printf("Error, allocation textures\n");
	if (check_for_texture(datos->info.we_texture, datos, flag) == 0)
		printf("Error, invalid texture\n");
	datos->we_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.we_texture, &width, &height);
	datos->we_texture->addr = mlx_get_data_addr(datos->we_texture->img, \
	&datos->we_texture->bpp, &datos->we_texture->size, \
	&datos->we_texture->endian);
}

void	init_ea_texture(t_main *datos)
{
	int	width;
	int	height;
	int	flag;

	flag = 4;
	if (datos->ea_texture == NULL)
		printf("Error, allocation textures\n");
	if (check_for_texture(datos->info.ea_texture, datos, flag) == 0)
		printf("Error, invalid texture\n");
	datos->ea_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.ea_texture, &width, &height);
	datos->ea_texture->addr = mlx_get_data_addr(datos->ea_texture->img, \
	&datos->ea_texture->bpp, &datos->ea_texture->size, \
	&datos->ea_texture->endian);
}
