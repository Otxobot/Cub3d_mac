#include "cubed.h"

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
