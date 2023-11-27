
#include "../cubed.h"

int check_for_map(char **elements_with_map)
{
	/*CREO que las funciones de antes no permiten que entre elementos pasase un trozo de mapa,
	por eso empiezo con un bucle de i < 6 para saltar los elementos y empezar a mirar el mapa
	lo digo con bastante certeza pero bueno, lo dejo aqui por que esta por ver aun.*/
	int i;
	int j;
	int a;
	int ph;
	char **map;
	
	j = 0;
	i = 0;
	a = 0;
	while (i < 6)
		i++;
	ph = i;
	while (elements_with_map[i])
	{
		j++;
		i++;
	}
	map = malloc(sizeof(char *) * (j + 1));
	while (elements_with_map[ph])
	{
		map[a] = elements_with_map[ph];
		a++;
		ph++;
	}
	map[a] = NULL;
	int b = 0;
	while (map[b])
		printf("map:%s\n", map[b++]);
	return (TRUE);
}
