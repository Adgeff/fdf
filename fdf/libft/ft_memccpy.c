/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:44:58 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:03:34 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;
	size_t				i;

	dstcpy = (unsigned char *)dst;
	srccpy = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		i++;
		if (dstcpy[i - 1] == (unsigned char)c)
			return (dst + i);
	}
	return (NULL);
}
