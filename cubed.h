/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:08 by abasante          #+#    #+#             */
/*   Updated: 2023/11/13 17:33:46 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUBED_H
# define CUBED_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_info 
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		f_color;
	int		c_color;
}			t_info;

//		PARSE:
t_info *extract_text(char *file_path);
int		is_cub(char *string);


#endif
