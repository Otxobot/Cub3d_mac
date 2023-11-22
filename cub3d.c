/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/11/22 17:36:22 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int main(int ac, char **av)
{
	t_info info;
	char	**elements_without_empty_lines;

	if (ac < 2)
		return (printf("Se te ha olvidad el archivo .cub!\n"), 1);
	else if (ac == 2)
	{
		if (is_cub(av[1]))
			return (printf("No es un archivo cub\n"), 1);
		elements_without_empty_lines = extract_elements(av[1]);
		if (!check_if_all_elements(elements_without_empty_lines))
		{
			printf("doesn't go through here\n");
			return (1);
		}
		printf("passes through here\n");
		// printf("1:%s\n", elements_without_empty_lines[0]);
		// printf("2:%s\n", elements_without_empty_lines[1]);
		// printf("3:%s\n", elements_without_empty_lines[2]);
		// printf("4:%s\n", elements_without_empty_lines[3]);
		// printf("5:%s\n", elements_without_empty_lines[4]);
		// printf("6:%s\n", elements_without_empty_lines[5]);
		// printf("7:%s\n", elements_without_empty_lines[6]);
		if (!categorize_elements(elements_without_empty_lines, &info))
		{
			return (1);
		}
		printf("========================================\n");
		printf("info->NO_texture:%s\n", info.no_texture);
		printf("info->SO_texture:%s\n", info.so_texture);
		printf("info->WE_texture:%s\n", info.we_texture);
		printf("info->EA_texture:%s\n", info.ea_texture);
		printf("F:%s\n", info.f_color);
		printf("C:%s\n", info.c_color);
		printf("========================================\n");
		//parse_map();
		//free_info_struct(info);
		ft_double_free (elements_without_empty_lines);
		return (0);
	}
}
