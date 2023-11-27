#include "cubed.h"

int check_for_map(char *string)
{
	int i;

	i = 0;
	printf("entering here\n");
	while (string[i] && (string[i] == ' ' || string[i] == '	'))
		i++;
	while (string[i] == '1' || string[i] == '0')
		return (TRUE);
	return (FALSE);
}
