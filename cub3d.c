/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/11/16 15:08:26 by abasante         ###   ########.fr       */
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
			return (1);
		categorize_elements(elements_without_empty_lines, &info);
		printf("%s\n", info.no_texture);
		printf("%s\n", info.so_texture);
		return (0);
	}
}
