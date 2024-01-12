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
	ft_double_free(datos->elements_without_empty_liness);
	exit (0);
}

int	handle_destroy2(void)
{
	exit (0);
}

int	handle_destroy3(t_main *datos)
{
	ft_double_free(datos->elements_without_empty_liness);
	exit (0);
}

int	handle_destroy_without_window(t_main *datos)
{
	free_things_inside_info_struct1(datos);
	ft_double_free(datos->elements_without_empty_liness);
	exit (0);
}
