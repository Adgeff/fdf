/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:08:49 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:04:51 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1cpy;
	const unsigned char	*s2cpy;
	size_t				i;

	s1cpy = (const unsigned char *)s1;
	s2cpy = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1cpy[i] == s2cpy[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((int)s1cpy[i] - (int)s2cpy[i]);
}
