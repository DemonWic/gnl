/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:27:31 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/16 11:21:21 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line)
{
	char buf[BUF_SIZE + 1];
	char *p;
	int ret;

	p = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[BUF_SIZE] = '\0';
		p = ft_strchr(buf, '\n');
		if ((!p) && k == 0 && !(line))
		{
			k++;
			if (!(line = ft_strnew(BUF_SIZE)))
				return (0);
			ft_strcpy(line, buf);
		}
		else if (p)
		{
			line = ft_strjoin(line, ft_strsub(buf, 0, (p - buf)));
		//	t_list->content = ft_strsub(buf, (p + 1), (BUF_SIZE - (p + 1)));
			break ;
		}
		else
			line = ft_strjoin(line, buf);
	}
}
	




int		main(int argc, char **argv)
{
	if (argc < 1)
		return (1);
	int fd1, fd2;
	char buf[30];
	fd1 = open(argv[1], O_RDONLY, 0);
	read(fd1, buf, 28);
	buf[29] ='\0';
	printf("%s\n", buf);
	fd2 = open(argv[2], O_RDONLY, 0);
	read(fd2, buf, 28);
	buf[29] = '\0';
	printf("%s\n", buf);
//	fd1 = open(argv[1], O_RDONLY, 0);
	read(fd1, buf, 28);
	buf[29] ='\0';
	printf("%s\n", buf);
//	fd2 = open(argv[2], O_RDONLY, 0);
	read(fd2, buf, 28);
	buf[29] = '\0';
	printf("%s\n", buf);
	return (0);
}
	
