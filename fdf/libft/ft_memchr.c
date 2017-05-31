/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:02:57 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:03:48 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*scpy;
	size_t				i;

	scpy = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (scpy[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
