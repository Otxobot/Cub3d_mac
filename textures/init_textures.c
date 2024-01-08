/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:18 by abasante          #+#    #+#             */
/*   Updated: 2024/01/08 16:15:16 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	init_textures(t_main *datos)
{ 
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;

	init_no_texture(datos, &no_texture);
	init_so_texture(datos, &so_texture);
	init_we_texture(datos, &we_texture);
	init_ea_texture(datos, &ea_texture);

	datos->no_texture = &no_texture;
	datos->so_texture = &so_texture;
	datos->we_texture = &we_texture;
	datos->ea_texture = &ea_texture;

}

void init_no_texture(t_main *datos, t_texture *no_texture)
{
	int width;
	int height;

	no_texture->addr = NULL;
	no_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.no_texture, &width, &height);
	no_texture->addr = mlx_get_data_addr(no_texture->img, &no_texture->bpp, &no_texture->size, &no_texture->endian);
}

void init_so_texture(t_main *datos, t_texture *so_texture)
{
	int width;
	int height;

	so_texture->addr = NULL;
	so_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.so_texture, &width, &height);
	so_texture->addr = mlx_get_data_addr(so_texture->img, &so_texture->bpp, &so_texture->size, &so_texture->endian);
}

void init_we_texture(t_main *datos, t_texture *we_texture)
{
	int width;
	int height;

	we_texture->addr = NULL;
	we_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.we_texture, &width, &height);
	we_texture->addr = mlx_get_data_addr(we_texture->img, &we_texture->bpp, &we_texture->size, &we_texture->endian);
}

void init_ea_texture(t_main *datos, t_texture *ea_texture)
{
	int width;
	int height;

	ea_texture->addr = NULL;
	ea_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.ea_texture, &width, &height);
	ea_texture->addr = mlx_get_data_addr(ea_texture->img, &ea_texture->bpp, &ea_texture->size, &ea_texture->endian);
}
