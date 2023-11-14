/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:56:43 by abasante          #+#    #+#             */
/*   Updated: 2023/11/14 11:30:47 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		t_len;
	char	*s3;
	size_t	n;
	size_t	m;

	if (!s1)
		return (ft_strdup(s2));
	n = 0;
	m = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(t_len * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[m] != '\0')
		s3[n++] = s1[m++];
	m = 0;
	while (s2[m] != '\0')
		s3[n++] = s2[m++];
	s3[n] = '\0';
	return (s3);
}

// int main(void)
// {
// 	char primero[] = "hello";
// 	char segundo[] = "hola";

// 	printf("%s\n", ft_strjoin(primero, segundo));
// 	return(0);
// }
