/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:36:47 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:10:39 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
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
	}
	return (dst);
}
