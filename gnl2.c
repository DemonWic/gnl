/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:36:45 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/22 17:09:04 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
# define BUFF_SIZE 32

t_list		*check(t_list *list, const int fd)
{
	t_list *nl;
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return (list);
		list = list->next;
	}
	nl = ft_lstnew("\0", (size_t)fd);
	ft_lstadd(&list, nl);
	return (list);
}

char	*set_n(char *buf, t_list *list, int *f)
{
	char *res;
	char *p;
	int k;
	int len;

	p = ft_strchr(buf, '\n');
	k = 0;
	len = ft_strlen(buf);
	if (!p)
		return (buf);
	else
	{
		k = p - buf;
		res = ft_strsub(buf, 0, k);
		p = ft_strsub(buf, (k + 1), len);
		free(list->content);
		list->content = p;
		f = 1;
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1]
	static t_list *list;
	t_list *nl;
	int ret;
	int f;

	nl = check(list, fd);
	f = 0;
	if (ft_strcmp(nl->content, "\0"))
		line = set_n(nl->content, nl);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		line = set_n(buf, nl, &f);
		(f) ? break : 0;
	}
	(!(ret) && f == 0) ? return (1) : return (0);
}	



int		main()
{
	t_list *list = ft_lstnew("BBB", 3);
	t_list *new;
	new = check(list, 4);
	printf("%s\n", new->content);
	printf("%zu\n", new->content_size);
	char buf[] = "Hello\nWorld";
	char *r = set_n(buf, new);
	printf("%s\n", r);
	printf("%s\n", new->content);
	printf("%zu\n", new->content_size);
	return (0);
}
