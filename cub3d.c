/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/11/14 14:13:35 by abasante         ###   ########.fr       */
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
	if (ac < 2)
		return (printf("Se te ha olvidad el archivo .cub!\n"), 1);
	else if (ac == 2)
	{
		if (is_cub(av[1]))
			return (printf("No es un archivo cub\n"), 1);
		extract_text(av[1]);
	}
}

// t_info *info = malloc(sizeof(t_info));
// 	if (!info)
// 		return (NULL);