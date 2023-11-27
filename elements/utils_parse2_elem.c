#include "../cubed.h"

int check_if_numbers_are_correct_size2(char *start)
{
    int a2;
    int a3;
    int i;

    a2 = 0;
    a3 = 0;
    i = 0;
    while (start[i] != ',')
    {
        a2++;
        i++;
    }
    if (a2 > 3)
        return (FALSE);
    i++;
    while (ft_isdigit(start[i]))
    {
        a3++;
        i++;
    }
    if (a3 > 3)
        return (FALSE);
    return (TRUE);
}

int check_if_numbers_are_correct_size1(char *start)
{
    int i;
    int a1;

    a1 = 0;
    i = 0;
    while (start[i] != ',')
    {
        a1++;
        i++;
    }
    if (a1 > 3)
        return (FALSE);
    i++;
    if (!check_if_numbers_are_correct_size2 (&start[i]))
        return (FALSE);
    return (TRUE);
}

char check_identifier(char *element)
{
    int i;

    i = 0;
    while (element[i] && (element[i] != 'E' && element[i] != 'N' && element[i] != 'S' && element[i] != 'W' &&\
    element[i] != 'F' && element[i] != 'C'))
        i++;
    if (element[i] == 'E')
        return ('E');
    else if (element[i] == 'N')
        return ('N');
    else if (element[i] == 'S')
        return ('S');
    else if (element[i] == 'W')
        return ('W');
    else if (element[i] == 'F')
        return ('F');
    else if (element[i] == 'C')
        return ('C');
    else
        return ('a');
}

int    RGB_atois(char identifier, char **nums, t_info *info)
{
    int a1;
	int a2;
	int a3;

    a1 = ft_atoi(nums[0]);
    a2 = ft_atoi(nums[1]);
    a3 = ft_atoi(nums[2]);
	if (a1 > 255 || a2 > 255 || a3 > 255)
		return (FALSE);
	if (identifier == 'F')
	{
		info->f_color[0] = a1;
		info->f_color[1] = a2;
		info->f_color[2] = a3;
	}
	else if (identifier == 'C')
	{
		info->c_color[0] = a1;
		info->c_color[1] = a2;
		info->c_color[2] = a3;
	}
    return (TRUE);
}

int	termina_con_xpm(const char *cadena)
{
	int			longitud_cadena;
	const char	*subcadena = ".xpm";
	int			longitud_subcadena;
	const char	*puntero_cadena = cadena;
	longitud_subcadena = 4;
	longitud_cadena = 0;
	while (*puntero_cadena != '\0')
	{
		longitud_cadena++;
		puntero_cadena++;
	}
	if (longitud_cadena < longitud_subcadena)
		return (0);
	puntero_cadena = cadena + longitud_cadena - longitud_subcadena;
	while (*puntero_cadena == *subcadena)
	{
		if (*puntero_cadena == '\0')
			return (1);
		puntero_cadena++;
		subcadena++;
	}
	return (0);
}
