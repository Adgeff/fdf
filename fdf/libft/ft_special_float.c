/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 07:29:09 by gargence          #+#    #+#             */
/*   Updated: 2016/09/27 16:40:37 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ret_inf(void)
{
	float		*infinite;
	int			intrep;

	intrep = 0x7F800000;
	infinite = (float *)&intrep;
	return (*infinite);
}

int				is_nan(double nbr)
{
	uintmax_t	*intrep;

	intrep = (uintmax_t *)&nbr;
	if (*intrep > 0x7FF0000000000000 && *intrep <= 0x7FFFFFFFFFFFFFFF)
		return (1);
	if (*intrep > 0xFFF0000000000000 && *intrep <= 0xFFFFFFFFFFFFFFFF)
		return (1);
	return (0);
}
