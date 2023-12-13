/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:08 by abasante          #+#    #+#             */
/*   Updated: 2023/12/13 12:43:43 by mikferna         ###   ########.fr       */
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
#define TAB_SIZE 4
#define SCREENWIDTH 1080
#define SCREENHEIGHT 640

typedef struct s_info 
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				f_color[3];
	int				c_color[3];
	char			player;
	char			**map;
}			t_info;

typedef struct s_main
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				size;
	int				endian;
	struct s_info	info;
}	t_main;

//=============PARSE_ELEMENTS:======================
char	**extract_elements(char *file_path);
int		is_cub(char *string);
int		empty_line(char *line);
char	**no_empty_lines(char *file_path, char **lines_ws);

//------------checks:----------------------
int		check_if_all_elements(char **elements);
int		check_for_NOSOWEEAFC(char *string);
int		check_for_NOSOWEEAFC_no_repeats(char *string);

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
int		termina_con_xpm(const char *cadena);
//----------------free:-----------------------
void	free_things_inside_info_struct(t_info info);

//============PARSE_MAP:=============================
int		parse_map(char **elements_with_map_maybe);
char 	**check_if_map_correct(char **map);
char	**set_null_terminator(char **map);

//-----------map_utils1:---------------------------
char	**check_for_map(char **elements_with_map);
int		check_characters(char **map);
int		check_how_many_tabs(char **map);
char	**replace_tabs_with_spaces(char **map_with_tabs);
int		check_how_many_tabs_in_a_line(char *line);

//-----------map_utils2:---------------------------
int		see_if_there_is_no_more_map(char **string);
int		check_if_walls_closed(char **map);
void	flood_fill(int x, int y, char **map);
int		calc_longest_line(char **map);
int		calc_amount_of_lines(char **map);
char **create_map_for_flood_fill(char **map, int longest_line_size, int amount_of_lines);


//-----------map_utils3:---------------------------
char	**allocate_and_initialize(int longest_line_size, int amount_of_lines, char **map_for_flood_fill);
void	sorround_border(char **map_for_flood_fill, int longest_line_size, int amount_of_lines);
void	map_inside_mffl(char **map, char **map_for_flood_fill);
int		check_if_closed(char **map, int longest_line_size, int amount_of_lines);	

#endif
