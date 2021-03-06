/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:03:45 by ahintz            #+#    #+#             */
/*   Updated: 2019/01/14 19:30:42 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (res);
}
