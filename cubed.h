/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:08 by abasante          #+#    #+#             */
/*   Updated: 2024/01/10 14:11:16 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define TAB_SIZE 4
# define SCREENWIDTH 1080
# define SCREENHEIGHT 640

# define MOVE_SPEED 0.25
# define UNIT 64

typedef struct s_info
{
	char				*no_texture;
	char				*so_texture;
	char				*we_texture;
	char				*ea_texture;
	int					f_color[3];
	int					c_color[3];
	char				player;
	char				**map;
	int					map_height;
}			t_info;
typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}				t_texture;

typedef struct s_main
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				size;
	int				endian;
	double			pa;
	double			px;
	double			py;
	struct s_info	info;
	t_texture		*no_texture;
	t_texture		*so_texture;
	t_texture		*we_texture;
	t_texture		*ea_texture;
}				t_main;

typedef struct s_colision
{
	double				first_impact;
	double				rest_of_impacts;
	double				startx;
	double				starty;
	double				endx;
	double				endy;
	double				dist;
	int					color[3];
	t_texture			*texture;
}				t_colision;

//=============PARSE_ELEMENTS:======================
int			parse(char **elements_without_empty_lines, \
t_main *datos, char *argument);
char		**extract_elements(char *file_path);
int			is_cub(char *string);
int			empty_line(char *line);
char		**no_empty_lines(char *file_path, char **lines_ws);

//------------checks:----------------------
int			check_if_all_elements(char **elements);
int			check_for_NOSOWEEAFC(char *string);
int			check_for_NOSOWEEAFC_no_repeats(char *string);

//------------categorizing elements:-------
int			categorize_elements(char **elements, t_info *info);
int			check_for_correct_path(char *element, t_info *info);
int			check_for_correct_RGB(char *element, t_info *info, char identifier);

//-----------------utils:------------------------
void		put_each_route_in_place_in_struct(char identifier, \
char *path_to_save_in_struct, t_info *info);
void		put_each_RGB_in_place_in_struct(char identifier_RGB, \
int *real_ints, t_info *info);
int			check_if_numbers_are_correct_size1(char *start);
int			check_if_numbers_are_correct_size2(char *start);
char		check_identifier(char *element);
int			RGB_atois(char identifier, char **nums, t_info *info);
int			termina_con_xpm(const char *cadena);
//----------------free:-----------------------
void		free_things_inside_info_struct(t_info info);
void		free_texture_structs(t_main *datos, int flag);

//============PARSE_MAP:=============================
int			parse_map(char **elements_with_map_maybe, t_info *info);
char		**check_if_map_correct(char **map);
char		**set_null_terminator(char **map);
void		player_and_map_in_info(char **map, t_info *info);

//-----------map_utils1:---------------------------
char		**check_for_map(char **elements_with_map);
int			check_characters(char **map, int a, int b, int player_is_there);
int			check_how_many_tabs(char **map);
char	**replace_tabs_with_spaces(char **map_with_tabs, int i, int a, int b);
int			check_how_many_tabs_in_a_line(char *line);

//-----------map_utils2:---------------------------
int			see_if_there_is_no_more_map(char **string);
int			check_if_walls_closed(char **map, int i);
void		flood_fill(int x, int y, char **map);
int			calc_longest_line(char **map);
int			calc_amount_of_lines(char **map);
char		**create_map_for_flood_fill(char **map, \
int longest_line_size, int amount_of_lines);

//-----------map_utils3:---------------------------
char		**allocate_and_initialize(int longest_line_size, \
int amount_of_lines, char **map_for_flood_fill);
void		sorround_border(char **map_for_flood_fill, \
int longest_line_size, int amount_of_lines);
void	sorround_border2(char **map_for_flood_fill, int longest_line_size, \
int amount_of_lines);
void		map_inside_mffl(char **map, char **map_for_flood_fill);
int			check_if_closed(char **map, int longest_line_size, \
int amount_of_lines);

//-----------load_screen1:---------------------------
int			obtener_color(int red, int green, int blue);
void		paint_fc(t_main *datos);
void		load_screen(t_main *datos);
double		max_and_min_angles(double player_angle);

//-----------init_values:---------------------------
void		p_ori(t_main *datos);
void		init_values(t_main *datos);

t_colision	colision(double fov_angle, double px, double py, t_main *datos);
void		draw_ray(t_main *datos, t_colision co, int x, int h);

int			move(char **map, double angle, t_main *game);
int			move_forward(t_main *game);
int			move_left(t_main *game);
int			move_back(t_main *game);
int			move_right(t_main *game);

int			calc_col_v_data(double ra, int px, int py, t_colision *c);
t_colision	col_v(double ra, int px, int py, t_main *data);
int			calc_col_h_data(double ra, int px, int py, t_colision *c);
t_colision	col_h(double ra, int px, int py, t_main *data);

void		init_textures(t_main *datos);
void		init_no_texture(t_main *datos);
void		init_so_texture(t_main *datos);
void		init_we_texture(t_main *datos);
void		init_ea_texture(t_main *datos);

void		init_mlx(t_main *datos);
int			check_for_texture(char *texture, t_main *datos, int flag);

char		**double_pointer_map(char **map_with_tabs);
void		haz_peque(char **map_without_tabs, int a, int *c);
char		**get_to_map(char **elements_with_map, int *ph);
#endif
