/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:32:34 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/16 17:50:42 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
char	ft(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	else
	{
		if (c >= 'a' && c <= 'z')
			c = c - 32;
		return (c);
	}
}

#include <stdio.h>
int	main(void)
{
	strcpy(str, "LoReM iPsUm");
    strmapi = ft_strmapi(str, &mapi);
    ft_print_result(strmapi);
    if (strmapi == str)
        ft_print_result("\nA new string was not returned");
    if (strmapi[11] != '\0')
        ft_print_result("\nString is not null terminated");
	//printf("%s", ft_strmapi("ciao", ft));
}
*/