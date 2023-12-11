#include "../cubed.h"

char **allocate_and_initialize(int longest_line_size, int amount_of_lines, char **map_for_flood_fill)
{
	int i;

	map_for_flood_fill = malloc(sizeof(char *) * (amount_of_lines + 3));
	i = 0;
	while (i < amount_of_lines + 2)
	{
		map_for_flood_fill[i] = malloc(sizeof(char) * (longest_line_size + 2));
		ft_memset(map_for_flood_fill[i], '*', longest_line_size + 2);
		map_for_flood_fill[i][longest_line_size + 1] = '\0';
		i++;
	}
	map_for_flood_fill[i] = NULL;
    return (map_for_flood_fill);
}

void sorround_border(char **map_for_flood_fill, int longest_line_size, int amount_of_lines)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map_for_flood_fill[i][j])
	{
		if (map_for_flood_fill[i][j] == '\n')
			j++;
		else
			map_for_flood_fill[i][j++] = '*';
	}
	i = 0;
	j = 0;
	while (map_for_flood_fill[i])
	{
		if (map_for_flood_fill[i][0])
			map_for_flood_fill[i][0] = '*';
		i++;
	}
	i = 0;
	j = 0;
	while (map_for_flood_fill[i])
	{
		j = 0;
		while (map_for_flood_fill[i][j])
		{
			if (j == longest_line_size + 1)
				map_for_flood_fill[i][j] = '*';
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (map_for_flood_fill[i][j])
	{
		map_for_flood_fill[amount_of_lines + 1][j] = '*';
		j++;
	}
}

void map_inside_mffl(char **map, char **map_for_flood_fill)
{
	int x;
	int y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != ' ' && map[x][y] != '\n')
				map_for_flood_fill[x + 1][y + 1] = map[x][y];
			y++;
		}
		x++;
	}
}

int check_if_closed(char **map)
{
	
}