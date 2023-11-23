/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:08 by abasante          #+#    #+#             */
/*   Updated: 2023/11/23 17:13:34 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUBED_H
# define CUBED_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct s_info 
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		f_color[3];
	int		c_color[3];
}			t_info;

//=============PARSE_ELEMENTS:======================
char	**extract_elements(char *file_path);
int		is_cub(char *string);
int		empty_line(char *line);
char	**no_empty_lines(char *file_path, char **lines_ws, char *line);

//------------checks:----------------------
int		check_if_all_elements(char **elements);
int		check_for_NOSOWEEAFC(char *string);

//------------categorizing elements:-------
int		categorize_elements(char **elements, t_info *info);
int		check_for_correct_path(char *element, t_info *info);
int		check_for_correct_RGB(char *element, t_info *info, char identifier);

//-----------------utils:------------------------
void	put_each_route_in_place_in_struct(char identifier, char *path_to_save_in_struct, t_info *info);
void	put_each_RGB_in_place_in_struct(char identifier_RGB, int *real_ints, t_info *info);
int		check_if_numbers_are_correct_size1(char *start);
int		check_if_numbers_are_correct_size2 (char *start);
char	check_identifier(char *element);
int		RGB_atois(char identifier, char **nums, t_info *info);

//----------------free:-----------------------
void	free_info_struct(t_info info);

//============PARSE_MAP:=============================


#endif
