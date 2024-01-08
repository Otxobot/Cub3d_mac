/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:53:50 by abasante          #+#    #+#             */
/*   Updated: 2024/01/08 13:25:39 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	handle_destroy(t_main *datos)
{
	mlx_destroy_window(datos->mlx, datos->window);
	return (0);
}

int key_hook(int keycode, t_main *datos)
{
    if (keycode == 53)
    {
        mlx_destroy_window(datos->mlx, datos->window);
        //free
        //exit(0);
        return (1);
    }
    else if (keycode == 124) //right arrow key
	{
        datos->pa = max_and_min_angles(datos->pa - 0.10471975512);
	}
    else if (keycode == 123)//left arrow key
	{
        datos->pa = max_and_min_angles(datos->pa + 0.10471975512);
	}
	else if (keycode == 0)//A
	{
		move_left(datos);
		// datos->px -= sin(datos->pa) * 0.25;
		// datos->py -= cos(datos->pa) * 0.25;
	}
	else if (keycode == 2)//D
	{
		move_right(datos);
		// datos->px += sin(datos->pa) * 0.25;
		// datos->py += cos(datos->pa) * 0.25;
	}
	else if (keycode == 13)//W
	{
		move_forward(datos);
		// datos->px += cos(datos->pa) * 0.25;
		// datos->py -= sin(datos->pa) * 0.25;
	}
	else if (keycode == 1)//S
	{
		move_back(datos);
		// datos->px -= cos(datos->pa) * 0.25;
		// datos->py += sin(datos->pa) * 0.25;
	}
    printf("Posición actual: (x: %.2f, y: %.2f)\n", datos->px, datos->py);
    printf("angulo->%.2f\n", datos->pa * (180/M_PI));
	load_screen(datos);
    return (0);
}

int main(int ac, char **av)
{
	t_main	datos;
	char	**elements_without_empty_lines;
	int 	exiting;

	elements_without_empty_lines = NULL;
	if (ac < 2)
		return (printf("Se te ha olvidad el archivo .cub!\n"), 1);
	else if (ac == 2)
	{
		if (parse(elements_without_empty_lines, &datos, av[1]))
			return (1);
		init_values(&datos);
		datos.mlx = mlx_init();
		datos.window = mlx_new_window(datos.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3d");
		datos.image = mlx_new_image(datos.mlx, SCREENWIDTH, SCREENHEIGHT);
		datos.addr = mlx_get_data_addr(datos.image, &datos.bits_per_pixel, &datos.size, &datos.endian);
		load_screen(&datos);
		exiting = mlx_hook(datos.window, 2, 1L<<0, key_hook, &datos);
		//mlx_hook(datos.window, 2, 1L<<0, &keypress, &datos);
		//mlx_hook(datos.window, 3, 1L<<1, &keyrealease, &datos);
		mlx_hook(datos.window, 17, 0, &handle_destroy, &datos);
		mlx_loop(datos.mlx);
		free_things_inside_info_struct(datos.info);
		ft_double_free (elements_without_empty_lines);
		printf("Exiting the program successfully!\n");
		if (exiting == 1)
			exit (0);
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