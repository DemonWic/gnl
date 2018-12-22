/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:27:31 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/13 19:50:13 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

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
	
