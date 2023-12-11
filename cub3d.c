/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/12/11 08:57:43 by abasante         ###   ########.fr       */
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
		if (elements_without_empty_lines[0] == NULL)
			return (printf("Esta vacio\n"), 1);
		if (!check_if_all_elements(elements_without_empty_lines))
			return (printf("Error\ncheck_if_all_elements\n"), 1);
		if (!categorize_elements(elements_without_empty_lines, &info))
			return (printf("Error\ncategorize elements\n"), 1);
		if (!parse_map(elements_without_empty_lines))
			return (printf("Error\nmap parse incorrect\n"), 1);
		//free_things_inside_info_struct(info);
		ft_double_free (elements_without_empty_lines);
		printf("Exiting the program successfully!\n");
		return (0);
	}
}

//JUST IN CASE I HAVE TO USE IT AGAIN->
										// printf("========================================\n");
										// printf("info->NO_texture:%s\n", info.no_texture);
										// printf("info->SO_texture:%s\n", info.so_texture);
										// printf("info->WE_texture:%s\n", info.we_texture);
										// printf("info->EA_texture:%s\n", info.ea_texture);
										// printf("Color rgb in F:\n");
										// printf("F1:%d\n", info.f_color[0]);
										// printf("F2:%d\n", info.f_color[1]);
										// printf("F3:%d\n", info.f_color[2]);
										// printf("Color rgb in C:\n");
										// printf("C1:%d\n", info.c_color[0]);
										// printf("C2:%d\n", info.c_color[1]);
										// printf("C3:%d\n", info.c_color[2]);
										// printf("========================================\n");