/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:21:59 by ahintz            #+#    #+#             */
/*   Updated: 2019/02/03 12:51:50 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoinc(char  *s1, char  *s2)
{
	int		i;
	int		j;
	int		size;
	char	*res;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(size);
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		if (s1[i])
			res[i] = s1[i];
		else if (s1[i] == '\0' && s2[j])
		{
			res[i] = s2[j];
			j++;
		}
		i++;
	}
	res[i] = '\0';
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (res);
}

static	t_list		*check(t_list **list, const int fd)
{
	t_list *nl;
	t_list *buf;
	buf = *list;
	while (buf)
	{
		if (buf->content_size == fd)
			return (buf);
		buf = buf->next;
	}
	nl = ft_lstnew(fd);
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
		ft_memdel((void **)&list->content);
		//free(list->content);
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
	if (tek->content != NULL)
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
			*line = ft_strjoinc(*line, set_n(buf, tek, &f));
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
	if (argc != 2)
		return (1);
	int fd1;
//	int fd2;
	char *line;
	fd1 = open(argv[1], O_RDONLY, 0);
//	fd2 = open(argv[2], O_RDONLY, 0);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
//	get_next_line(fd1, &line);
//	printf("%s\n", line);
//	free(line);
	return (0);
}
