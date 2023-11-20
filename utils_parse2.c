#include "cubed.h"

int check_if_numbers_are_correct_size(char *start)
{
    int i;
    int a1;
    int a2; 
    int a3;

    a1 = 0;
    a2 = 0;
    a3 = 0;
    i = 0;
    while (start[i] != ',')
    {
        a1++;
        i++;
    }
    if (a1 > 3)
        return (FALSE);
    i++;
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
