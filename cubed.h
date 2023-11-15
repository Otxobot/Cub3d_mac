/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:08 by abasante          #+#    #+#             */
/*   Updated: 2023/11/14 16:52:44 by abasante         ###   ########.fr       */
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

typedef struct s_info 
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		f_color;
	int		c_color;
}			t_info;

typedef struct s_elem{
    char    NO[3];
    char    SO[3];
    char    WE[3];
    char    EA[3];
    char    F[2];
    char    C[2];
}				t_elem;

//		PARSE:
char	**extract_elements(char *file_path);
int		is_cub(char *string);
int		empty_line(char *line);
char	**no_empty_lines(char *file_path, char **lines_ws, char *line);
int		check_if_all_elements(char **elements);
//		checks
int		check_for_NO(char *string);
int		check_for_SO(char *string);

t_elem	init_elements_id();

#endif
