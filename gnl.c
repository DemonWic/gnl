/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:36:45 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/19 21:11:39 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list		*check(t_list *list, const int fd)
{
	t_list *nl;
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return (list);
		list = list->next;
	}
	nl = ft_lstnew("AAA", (size_t)fd);
	ft_lstadd(&list, nl);
	return (list);
}

int		main()
{
	t_list *list = ft_lstnew("BBB", 3);
	t_list *new;
	new = check(list, 4);
	printf("%s\n", new->content);
	printf("%zu\n", new->content_size);
	return (0);
}
