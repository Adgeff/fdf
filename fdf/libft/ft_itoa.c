/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:13:01 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:01:23 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		convert(int n, int power, char *nbr)
{
	if (n < 0)
	{
		*nbr = '-';
		nbr++;
		n = n * (-1);
	}
	while (power >= 1)
	{
		*nbr = n / power + '0';
		nbr++;
		n = n - (n / power * power);
		power = power / 10;
	}
	*nbr = '\0';
}

char			*ft_itoa(int n)
{
	int			power;
	int			size;
	char		*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = 1;
	if (n < 0)
		size++;
	power = 1;
	while ((n / power >= 10 && n >= 0) || (n / power <= (-10) && n < 0))
	{
		power = power * 10;
		size++;
	}
	nbr = (char *)malloc(size + 1);
	if (nbr != NULL)
		convert(n, power, nbr);
	return (nbr);
}
