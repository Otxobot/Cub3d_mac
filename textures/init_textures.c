/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:18 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 17:35:14 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_for_texture(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		printf("pasa por aqui\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	init_textures(t_main *datos)
{
	if (init_no_texture(datos))
		return (1);
	if (init_so_texture(datos))
		return (1);
	if (init_we_texture(datos))
		return (1);
	if (init_ea_texture(datos))
		return (1);
	return (0);
}

int	init_no_texture(t_main *datos)
{
	int	width;
	int	height;

	if (datos->no_texture == NULL)
		printf("Error, one texture allocation is not correct\n");
	if (check_for_texture(datos->info.no_texture))
		return (1);
	datos->no_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.no_texture, &width, &height);
	datos->no_texture->addr = mlx_get_data_addr(datos->no_texture->img, \
	&datos->no_texture->bpp, &datos->no_texture->size, \
	&datos->no_texture->endian);
	return (0);
}

int	init_so_texture(t_main *datos)
{
	int	width;
	int	height;

	if (datos->so_texture == NULL)
		printf("Error, one texture allocation is not correct\n");
	if (check_for_texture(datos->info.so_texture))
		return (1);
	datos->so_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.so_texture, &width, &height);
	datos->so_texture->addr = mlx_get_data_addr(datos->so_texture->img, \
	&datos->so_texture->bpp, &datos->so_texture->size, \
	&datos->so_texture->endian);
	return (0);
}
