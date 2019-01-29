/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:21:59 by ahintz            #+#    #+#             */
/*   Updated: 2019/01/29 20:58:03 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static	t_list		*check(t_list **list, const int fd)
{
	t_list *nl;
	t_list *buf;
	buf = *list;
	while (buf)
	{
		if ((int)buf->content_size == fd)
			return (buf);
		buf = buf->next;
	}
	nl = ft_lstnew("\0", (size_t)fd);
	ft_lstadd(list, nl);
	return (nl);
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
	int ret;
	int f;
	int k;
	t_list 		*tek;

	tek = check(&list, fd);
	f = 0;
	k = 0;
	if (ft_strcmp(tek->content, "\0"))
	{
		*line = set_n(tek->content, tek, &f);
		k = 1;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) && !f)
	{
		buf[ret] = '\0';
		if (!k)
		{
			*line = ft_strdup(set_n(buf, tek, &f));
			k = 1;
		}
		else
		{
			char *p;
			p = *line;
			*line = ft_strjoin(*line, set_n(buf, tek, &f));
			free(p);
		}
		if (f)
		{
			break ;
		}
	}
	if(!ret && (f == 0))
		return (-1);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	int fd1;
	int fd2;
	int ret;
	char *line;
	fd1 = open(argv[1], O_RDONLY, 0);
	fd2 = open(argv[2], O_RDONLY, 0);
	ret = get_next_line(fd1, &line);
	printf("%s %i\n", line, ret);
	ret = get_next_line(fd2, &line);
	printf("%s %i\n", line, ret);
	ret = get_next_line(fd1, &line);
	printf("%s %i\n", line, ret);
	ret = get_next_line(fd2, &line);
	printf("%s %i\n", line, ret);
	return (0);
}
