/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/11/13 15:36:31 by abasante         ###   ########.fr       */
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

int is_cub(char *string)
{
	int i;

	i = 0;
	i = ft_strlen(string) - 1;

	if (string[i--] != 'b')
		return (1);
	if (string[i--] != 'u')
		return (1);
	if (string[i--] != 'c')
		return (1);
	if (string[i--] != '.')
		return (1);
	return (0);
}

void extract_text(char *string)
{
	
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Se te ha olvidad el archivo .cub!\n"), 1);
	else if (ac == 2)
	{
		if (is_cub(av[1]))
			return (printf("no es un archivo cub\n"), 1);
		extract_text(av[1]);
	}
}
