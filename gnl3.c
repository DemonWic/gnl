/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:36:45 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/22 18:26:57 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
# define BUFF_SIZE 4


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
		*f = 1;
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	static t_list *list;
	t_list *nl;
	int ret;
	int f;
	int k;

	nl = check(list, fd);
	f = 0;
	k = 0;
	if (ft_strcmp(nl->content, "\0"))
	{
		*line = set_n(nl->content, nl, 0);
		k = 1;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!k)
		{
			*line = ft_strdup(buf);
			k = 1;
		}
		else
			*line = ft_strjoin(*line, set_n(buf, nl, &f));
		if (f)
			break ;
	}
	if(!ret && (f == 0))
		return (-1);
	return (1);
}	



int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int fd;
	char *res;
	fd = open(argv[1], O_RDONLY, 0);
	get_next_line(fd, &res);
	printf("%s\n", res);
	get_next_line(fd, &res);
	printf("%s\n", res);
	return (0);
}
