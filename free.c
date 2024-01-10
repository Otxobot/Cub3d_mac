/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:24:47 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 12:08:33 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_things_inside_info_struct(t_info info)
{
	free (info.no_texture);
	free (info.so_texture);
	free (info.we_texture);
	free (info.ea_texture);
	ft_double_free(info.map);
}

void	free_texture_structs(t_main *datos, int flag)
{
	if (flag == 1)
	{
		free(datos->no_texture);
		exit(-1);
	}
	if (flag == 2)
	{
		free(datos->so_texture);
		exit(-1);
	}
	if (flag == 3)
	{
		free(datos->we_texture);
		exit(-1);
	}
	if (flag == 4)
	{
		free(datos->ea_texture);
		exit(-1);
	}
}
