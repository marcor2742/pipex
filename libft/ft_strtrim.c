/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:57:53 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/18 15:08:18 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (j > i && ft_strchr(set, s1[j]) != NULL)
		j--;
	cpy = malloc(sizeof(char) * (j - i + 2));
	if (cpy == NULL)
		return (NULL);
	ft_memcpy(cpy, s1 + i, j - i + 1);
	cpy[j - i + 1] = '\0';
	return (cpy);
}

/*
#include <stdio.h>
int main()
{
    printf("%s", ft_strtrim("ananxanananan", "an"));
}
*/