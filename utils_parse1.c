/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:26 by abasante          #+#    #+#             */
/*   Updated: 2023/11/13 15:57:39 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
