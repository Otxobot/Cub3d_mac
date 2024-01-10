/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:07:18 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 14:18:51 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_for_texture(char *texture, t_main *datos, int flag)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		free_texture_structs(datos, flag);
		return (0);
	}
	close(fd);
	return (1);
}

void	init_textures(t_main *datos)
{
	init_no_texture(datos);
	init_so_texture(datos);
	init_we_texture(datos);
	init_ea_texture(datos);
}

void	init_no_texture(t_main *datos)
{
	int	width;
	int	height;
	int	flag;

	flag = 1;
	if (!datos->no_texture)
		printf("Error, allocation textures\n");
	if (check_for_texture(datos->info.no_texture, datos, flag) == 0)
		printf("Error, invalid texture\n");
	datos->no_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.no_texture, &width, &height);
	datos->no_texture->addr = mlx_get_data_addr(datos->no_texture->img, \
	&datos->no_texture->bpp, &datos->no_texture->size, \
	&datos->no_texture->endian);
}

void	init_so_texture(t_main *datos)
{
	int	width;
	int	height;
	int	flag;

	flag = 2;
	if (datos->so_texture == NULL)
		printf("Error, allocation textures\n");
	if (check_for_texture(datos->info.so_texture, datos, flag) == 0)
		printf("Error, invalid texture\n");
	datos->so_texture->img = mlx_xpm_file_to_image(datos->mlx, \
	datos->info.so_texture, &width, &height);
	datos->so_texture->addr = mlx_get_data_addr(datos->so_texture->img, \
	&datos->so_texture->bpp, &datos->so_texture->size, \
	&datos->so_texture->endian);
}