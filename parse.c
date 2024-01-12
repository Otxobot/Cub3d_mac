/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:43:32 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 18:24:09 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	big_parse(char **elements_without_empty_lines, t_main *datos, char *arguments)
{
	int ret;

	ret = 0;
	ret = parse(elements_without_empty_lines, datos, arguments); 
	if (ret == 1)
	{
		handle_destroy_without_window(datos);
	}
	else if (ret == 3)
	{
		printf("Error\nEsta vacio\n");
		handle_destroy1(datos);
	}
	else if (ret == 2)
	{
		handle_destroy2();
	}
	else if (ret == 4)
		handle_destroy2();
	return (0);
}

int	parse(char **elements_without_empty_lines, t_main *datos, char *argument)
{
	if (is_cub(argument))
		return (printf("No es un archivo cub\n"), 2);
	elements_without_empty_lines = extract_elements(argument, 0, 0, 0);
	datos->elements_without_empty_liness = elements_without_empty_lines;
	if (elements_without_empty_lines == NULL)
		return (3);
	if (elements_without_empty_lines[0] == NULL)
		return (3);
	if (!check_if_all_elements(elements_without_empty_lines))
		return (printf("Error\ncheck_if_all_elements\n"), 4);
	if (!categorize_elements(elements_without_empty_lines, &datos->info))
		return (printf("Error\ncategorize elements\n"), 1);
	if (!parse_map(elements_without_empty_lines, &datos->info))
	{
		printf("pasamos por aqui\n");
		return (printf("Error\nmap parse incorrect"), 1);
	}
	return (0);
}
