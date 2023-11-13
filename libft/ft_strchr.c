/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:03:54 by abasante          #+#    #+#             */
/*   Updated: 2023/11/13 18:13:43 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*chr;

// 	chr = (char *)s;
// 	while (*chr != (char)c)
// 	{
// 		if (!*chr)
// 			return (NULL);
// 		chr++;
// 	}
// 	return (chr);
// }

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char s[50] = "This is my string";

// 	printf("%s", ft_strchr(s, 'n'));
// 	return(0);
// }
