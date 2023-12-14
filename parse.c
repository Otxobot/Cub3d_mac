/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:43:32 by abasante          #+#    #+#             */
/*   Updated: 2023/12/14 13:25:14 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int parse(char **elements_without_empty_lines, t_main *datos, char *argument)
{
	if (is_cub(argument))
		return (printf("No es un archivo cub\n"), 1);
	elements_without_empty_lines = extract_elements(argument);
	if (elements_without_empty_lines == NULL)
		return (printf("Esta vacio1\n"), 1);	
	if (elements_without_empty_lines[0] == NULL)
		return (printf("Esta vacio\n"), 1);
	if (!check_if_all_elements(elements_without_empty_lines))
		return (printf("Error\ncheck_if_all_elements\n"), 1);
	if (!categorize_elements(elements_without_empty_lines, &datos->info))
		return (printf("Error\ncategorize elements\n"), 1);
	if (!parse_map(elements_without_empty_lines, &datos->info))
		return (printf("Error\nmap parse incorrect"), 1);
	return (0);
}
