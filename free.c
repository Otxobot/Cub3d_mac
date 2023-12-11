/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:24:47 by abasante          #+#    #+#             */
/*   Updated: 2023/11/28 19:25:52 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_things_inside_info_struct(t_info info)
{
	free (info.no_texture);
	free (info.so_texture);
	free (info.we_texture);
	free (info.ea_texture);
	// free (info.c_color);
	// free (info.f_color);
}
