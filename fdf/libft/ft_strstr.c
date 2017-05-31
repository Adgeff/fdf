/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:12:08 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:09:23 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t s1len;
	size_t s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s2len == 0)
		return ((char *)s1);
	while (s2len <= s1len)
	{
		if (ft_strncmp(s1, s2, s2len) == 0)
			return ((char *)s1);
		s1++;
		s1len--;
	}
	return (NULL);
}
