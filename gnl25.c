/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:21:59 by ahintz            #+#    #+#             */
/*   Updated: 2019/02/10 14:47:14 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int set_n(char **temp, char ***line)
{
	int k;
	char *p;
	char *ptr;
	int res;
	int len;
	
	k = 0;
	res = 0;
	len = ft_strlen(*temp);
	p = ft_strchr(*temp, '\n');
	if (!p)
	{
		**line = *temp;
		return (0);
	}
	else
	{
		k = p - *temp;
		ptr = ft_strsub(*temp, 0, k);
		**line = ft_strdup(ptr);
		free(ptr);
		p = ft_strsub(*temp, (k + 1), len);
		free(*temp);
		*temp = p;
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	static char *temp;
	int ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (temp &&(set_n(&temp, &line)))
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(temp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (set_n(&temp, &line))
		return(1);
	return (-1);
}
