/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:00:15 by mruggier          #+#    #+#             */
/*   Updated: 2023/10/19 16:56:38 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_content;
	t_list	*new;

	new = NULL;
	while (lst != NULL)
	{
		new_content = ft_lstnew(f(lst->content));
		if (new_content == NULL)
		{
			ft_lstclear(&new, del);
			free(new);
			return (NULL);
		}
		ft_lstadd_back(&new, new_content);
		lst = lst->next;
	}
	return (new);
}
