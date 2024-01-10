/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:24:47 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 17:28:26 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_things_inside_info_struct(t_main *datos)
{
	free (datos->info.no_texture);
	free (datos->info.so_texture);
	free (datos->info.we_texture);
	free (datos->info.ea_texture);
	ft_double_free(datos->info.map);
	free(datos->no_texture);
	free(datos->so_texture);
	free(datos->we_texture);
	free(datos->ea_texture);
}

// void	free_texture_structs(t_main *datos, int flag)
// {
// 	if (flag == 1)
// 	{
// 		free(datos->no_texture);
// 	}
// 	if (flag == 2)
// 	{
// 		free(datos->so_texture);
// 	}
// 	if (flag == 3)
// 	{
// 		free(datos->we_texture);
// 	}
// 	if (flag == 4)
// 	{
// 		free(datos->ea_texture);
// 	}
// }
