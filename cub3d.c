/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/11/14 16:57:21 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// int main(void)
// {
// 	void *init;
// 	void *mlx_win;

// 	init = 	mlx_init();

// 	mlx_win = mlx_new_window(init, 1920, 1080, "Hello World!");
// 	mlx_loop(init);	
// }

int main(int ac, char **av)
{
	t_info *info;
	char	**elements_without_empty_lines;

	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (ac < 2)
		return (printf("Se te ha olvidad el archivo .cub!\n"), 1);
	else if (ac == 2)
	{
		if (is_cub(av[1]))
			return (printf("No es un archivo cub\n"), 1);
		elements_without_empty_lines = extract_elements(av[1]);
		check_if_all_elements(elements_without_empty_lines);
		//categorize_elements(elements_without_empty_lines, info);
	}
}
