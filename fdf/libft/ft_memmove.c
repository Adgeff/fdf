/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:53:58 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:05:07 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;
	unsigned char		*srcdup;
	size_t				i;

	dstcpy = (unsigned char *)dst;
	srccpy = (const unsigned char *)src;
	srcdup = (unsigned char *)malloc(len);
	i = 0;
	while (i < len)
	{
		srcdup[i] = srccpy[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dstcpy[i] = srcdup[i];
		i++;
	}
	free(srcdup);
	return (dst);
}
