/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahintz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:03:45 by ahintz            #+#    #+#             */
/*   Updated: 2018/12/01 15:58:37 by ahintz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(size);
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		if (*s1)
			*res++ = *s1++;
		if (*s1 == '\0' && *s2)
			*res++ = *s2++;
		i++;
	}
	*res = '\0';
	return (res - (i - 1));
}
