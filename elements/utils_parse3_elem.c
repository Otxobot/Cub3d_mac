/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse3_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:32:27 by abasante          #+#    #+#             */
/*   Updated: 2024/01/11 10:32:30 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_for_correct_rgb(char *element, t_info *info, char identifier)
{
	int		i;
	char	*set;
	char	*letse;
	char	**nums;

	set = "FC 	";
	i = 0;
	letse = ft_strtrim(element, set);
	while (letse[i])
	{
		if (ft_isalpha(letse[i]))
		{
			return (free(letse), FALSE);
		}
		i++;
	}
	nums = ft_split(letse, ',');
	if (nums[0] == NULL || nums[1] == NULL || nums[2] == NULL)
		return (free(letse), ft_double_free(nums), FALSE);
	if (!rgb_atois(identifier, nums, info))
		return (free(letse), ft_double_free(nums), FALSE);
	free (letse);
	ft_double_free(nums);
	return (TRUE);
}

char	**maloc_lines_ws(char **lines_ws, int a, char *file_path, int fd)
{
	lines_ws = malloc(sizeof(char *) * (a + 1));
	close(fd);
	lines_ws = no_empty_lines(file_path, lines_ws);
	return (lines_ws);
}

int	check_if_all_elements(char **elements)
{
	int	i;
	int	all_elements_done;

	all_elements_done = 0;
	i = 0;
	while (elements[i])
	{
		if (all_elements_done == 6)
			break ;
		if (!check_for_elements(elements[i]))
		{
			ft_double_free (elements);
			return (FALSE);
		}
		all_elements_done++;
		i++;
	}
	return (TRUE);
}
