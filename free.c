/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:24:47 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 17:27:32 by abasante         ###   ########.fr       */
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

void	free_things_inside_info_struct1(t_main *datos)
{
	free (datos->info.no_texture);
	free (datos->info.so_texture);
	free (datos->info.we_texture);
	free (datos->info.ea_texture);
}
