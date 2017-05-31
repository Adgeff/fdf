/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:50:41 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:05:31 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nbr, unsigned int power)
{
	int	result;

	result = 1;
	if (power >= 1)
		result = nbr * ft_power(nbr, power - 1);
	return (result);
}
