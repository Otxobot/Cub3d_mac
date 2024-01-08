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
}

void	init_no_texture(t_main *datos, t_texture *no_texture)
{
	no_texture->img = mlx_xpm_file_to_image(datos->mlx, datos->info.no_texture, &no_texture->width, &no_texture->height);
	no_texture->addr = mlx_get_data_addr(no_texture->img, &no_texture->bits_per_pixel, &no_texture->line_length, &no_texture->endian);
}
