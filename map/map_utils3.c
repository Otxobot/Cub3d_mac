#include "../cubed.h"

char **allocate_and_initialize(int longest_line_size, int amount_of_lines, char **map_for_flood_fill)
{
	int i;
	//int j;

	map_for_flood_fill = malloc(sizeof(char *) * (amount_of_lines + 2));
	i = 0;
	//j = 0;
	while (i < amount_of_lines + 2)
	{
		map_for_flood_fill[i] = malloc(sizeof(char) * (longest_line_size + 3));
		ft_memset(map_for_flood_fill[i], '$', longest_line_size + 3);
		map_for_flood_fill[i][longest_line_size + 2] = '\0';
		printf("%d\n", i);
		i++;
	}
	map_for_flood_fill[i] = NULL;
	i = 0;
	while (map_for_flood_fill[i] != NULL)
		printf("%s\n", map_for_flood_fill[i++]);
    return (map_for_flood_fill);
}
