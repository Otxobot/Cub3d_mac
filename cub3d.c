/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 17:33:59 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	handle_destroy(t_main *datos)
{
	mlx_destroy_window(datos->mlx, datos->window);
	free_things_inside_info_struct(datos);
	ft_double_free(datos->elements_without_empty_liness);
	exit (0);
}

int	handle_destroy1(t_main *datos)
{
	free_things_inside_info_struct1(datos);
	ft_double_free(datos->elements_without_empty_liness);
	exit (0);
}

int	key_hook(int keycode, t_main *datos)
{
	if (keycode == 53)
	{
		mlx_destroy_window(datos->mlx, datos->window);
		free_things_inside_info_struct(datos);
		ft_double_free(datos->elements_without_empty_liness);
		exit (1);
	}
	else if (keycode == 124)
		datos->pa = max_and_min_angles(datos->pa - 0.10471975512);
	else if (keycode == 123)
		datos->pa = max_and_min_angles(datos->pa + 0.10471975512);
	else if (keycode == 0)
		move_left(datos);
	else if (keycode == 2)
		move_right(datos);
	else if (keycode == 13)
		move_forward(datos);
	else if (keycode == 1)
		move_back(datos);
	load_screen(datos);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	datos;
	char	**elements_without_empty_lines;

	elements_without_empty_lines = NULL;
	if (ac < 2)
		return (printf("Se te ha olvidad el archivo .cub!\n"), 1);
	else if (ac == 2)
	{
		if (parse(elements_without_empty_lines, &datos, av[1]))
			return (handle_destroy1(&datos), 1);
		datos.mlx = mlx_init();
		datos.window = mlx_new_window(datos.mlx, SCREENWIDTH, \
		SCREENHEIGHT, "cub3d");
		init_values(&datos);
		datos.image = mlx_new_image(datos.mlx, SCREENWIDTH, SCREENHEIGHT);
		datos.addr = mlx_get_data_addr(datos.image, \
		&datos.bits_per_pixel, &datos.size, &datos.endian);
		if (init_textures(&datos))
			return (handle_destroy(&datos), 1);
		load_screen(&datos);
		mlx_hook(datos.window, 2, (1L << 0), &key_hook, &datos);
		mlx_hook(datos.window, 17, 0, &handle_destroy, &datos);
		mlx_loop(datos.mlx);
		mlx_loop_hook(datos.mlx, &load_screen, &datos);
		free_things_inside_info_struct(&datos);
		ft_double_free (elements_without_empty_lines);
		printf("exiting the program succesfully!\n");
		return (0);
	}
}

		// printf("========================================\n");
		// printf("info->NO_texture:%s\n", datos.info.no_texture);
		// printf("info->SO_texture:%s\n", datos.info.so_texture);
		// printf("info->WE_texture:%s\n", datos.info.we_texture);
		// printf("info->EA_texture:%s\n", datos.info.ea_texture);
		// printf("Color rgb in F:\n");
		// printf("F1:%d\n", datos.info.f_color[0]);
		// printf("F2:%d\n", datos.info.f_color[1]);
		// printf("F3:%d\n", datos.info.f_color[2]);
		// printf("Color rgb in C:\n");
		// printf("C1:%d\n", datos.info.c_color[0]);
		// printf("C2:%d\n", datos.info.c_color[1]);
		// printf("C3:%d\n", datos.info.c_color[2]);
		// printf("player and map:\n");
		// printf("player:%c\n", datos.info.player);
		// int a = 0;
		// while (datos.info.map[a])
		// 	printf("%s", datos.info.map[a++]);
		//printf("========================================\n");