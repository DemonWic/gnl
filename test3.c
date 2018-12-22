/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:27:31 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/19 20:27:06 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
# define BUF_SIZE 32



t_list		*ft_check_fd(t_list *nl, const int fd, char **line)
{
	while (nl)
	{
		if (nl->content_size == (unsigned int)fd)
		{
			*line = nl->content;
			return (nl);
		}
		nl = nl->next;
	}
//	ft_lstadd(&nl, ft_lstnew("\0", fd));
	if (!(nl = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		nl->content = NULL;
		nl->content_size = fd;
		nl->next = NULL;
	}
	return (nl);
}

//t_size		*ft_addlst(t_size nl, char *content, const int fd)
//{


int		get_next_line(const int fd, char **line)
{
	char buf[BUF_SIZE + 1];
	static t_list *nl;
	char *p;
	int ret;
	int k;

	p = NULL;
	k = 0;
	nl = ft_check_fd(nl, fd, line);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		p = ft_strchr(buf, '\n');
		if (!p && k == 0 && !(*line))
		{
			k++;
			if (!(*line = ft_strnew(ret)))
				return (1);
			ft_strcpy(*line, buf);
		}
		else if (p)
		{
			*line = ft_strjoin(*line, ft_strsub(buf, 0, (p - buf)));
	//		nl->content = ft_strsub(buf, (p + 1), (BUF_SIZE - (p + 1)));
	//		nl = ft_addlst(nl, (ft_strsub(buf, 0, (p - buf))), fd);
			if (p == &buf[ret - 1])
				nl->content = ft_strsub(buf, ((p - buf) + 1), (BUF_SIZE - ((p - buf) + 1)));
			break ;
		}
		else
			*line = ft_strjoin(*line, buf);
	}
	return (0);
}
	




int		main(int argc, char **argv)
{
	if (argc < 1)
		return (1);
	int fd1;
	char *res;
	fd1 = open(argv[1], O_RDONLY, 0);
	get_next_line(fd1, &res);

	printf("%s\n", res);
	char *res1;
	get_next_line(fd1, &res1);
	printf("%s\n", res1);
	return (0);
}
	
