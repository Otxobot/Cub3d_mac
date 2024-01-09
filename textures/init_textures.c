/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:18 by abasante          #+#    #+#             */
/*   Updated: 2024/01/09 12:59:27 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	init_textures(t_main *datos)
{ 
	// t_texture	no_texture;
	// t_texture	so_texture;
	// t_texture	we_texture;
	// t_texture	ea_texture;

	init_no_texture(datos);
	init_so_texture(datos);
	init_we_texture(datos);
	init_ea_texture(datos);

	// datos->no_texture = &no_texture;
	// datos->so_texture = &so_texture;
	// datos->we_texture = &we_texture;
	// datos->ea_texture = &ea_texture;
}

void init_no_texture(t_main *datos)
{
	int width;
	int height;

	datos->no_texture = (t_texture *)malloc(sizeof(t_texture));
	datos->no_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.no_texture, &width, &height);
	datos->no_texture->addr = mlx_get_data_addr(datos->no_texture->img, &datos->no_texture->bpp, &datos->no_texture->size, &datos->no_texture->endian);
}

void init_so_texture(t_main *datos)
{
	int width;
	int height;

	datos->so_texture = (t_texture *)malloc(sizeof(t_texture));
	datos->so_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.so_texture, &width, &height);
	datos->so_texture->addr = mlx_get_data_addr(datos->so_texture->img, &datos->so_texture->bpp, &datos->so_texture->size, &datos->so_texture->endian);
}

void init_we_texture(t_main *datos)
{
	int width;
	int height;

	datos->we_texture = (t_texture *)malloc(sizeof(t_texture));
	datos->we_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.we_texture, &width, &height);
	datos->we_texture->addr = mlx_get_data_addr(datos->we_texture->img, &datos->we_texture->bpp, &datos->we_texture->size, &datos->we_texture->endian);
}

void init_ea_texture(t_main *datos)
{
	int width;
	int height;

	datos->ea_texture = (t_texture *)malloc(sizeof(t_texture));
	datos->ea_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.ea_texture, &width, &height);
	datos->ea_texture->addr = mlx_get_data_addr(datos->ea_texture->img, &datos->ea_texture->bpp, &datos->ea_texture->size, &datos->ea_texture->endian);
}

