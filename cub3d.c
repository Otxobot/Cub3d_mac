/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2023/12/14 11:26:59 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	handle_destroy(t_main *datos)
{
	mlx_destroy_window(datos->mlx, datos->window);
	return (0);
}

// int obtener_color(int red, int green, int blue)
// {
//     return (red << 16) | (green << 8) | blue;
// }

void paint_fc(t_main *datos)
{
    int i, j;

    j = 0;
    while (j < SCREENHEIGHT)
    {
        i = 0;
        while (i < SCREENWIDTH)
        {
            if (j < SCREENHEIGHT / 2)
                mlx_pixel_put(datos->mlx, datos->window, i, j, obtener_color(datos->info.c_color[0], datos->info.c_color[1], datos->info.c_color[2]));
            else
                mlx_pixel_put(datos->mlx, datos->window, i, j, obtener_color(datos->info.f_color[0], datos->info.f_color[1], datos->info.f_color[2]));
            i++;
        }
        j++;
    }
}

int main(int ac, char **av)
{
	t_main	datos;

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
		if (!categorize_elements(elements_without_empty_lines, &datos.info))
			return (printf("Error\ncategorize elements\n"), 1);
		if (!parse_map(elements_without_empty_lines, &datos.info))
			return (printf("Error\nmap parse incorrect"), 1);
		datos.mlx = mlx_init();
		datos.window = mlx_new_window(datos.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3d");
		datos.image = mlx_new_image(datos.mlx, SCREENWIDTH, SCREENHEIGHT);
		datos.addr = mlx_get_data_addr(datos.image, &datos.bits_per_pixel, &datos.size, &datos.endian);
		paint_fc(&datos);
		//mlx_clear_window(datos.mlx, datos.window);
		//mlx_hook(datos.window, 17, 0, &handle_destroy, &datos);
		//mlx_hook(datos.window, 2, 0, &movements, &datos);
		mlx_loop(datos.mlx);

		free_things_inside_info_struct(datos.info);
		ft_double_free (elements_without_empty_lines);
		printf("Exiting the program successfully!\n");
		return (0);
	}
}

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
		// printf("player and map:\n");
		// printf("player:%c\n", info.player);
		// int a = 0;
		// while (info.map[a])
		// 	printf("%s", info.map[a++]);
		// printf("========================================\n");
