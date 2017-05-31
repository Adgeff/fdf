/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:27:02 by gargence          #+#    #+#             */
/*   Updated: 2016/10/21 08:00:48 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isint2(const char *s, int sign)
{
	int		i;
	char	*max;

	i = 0;
	max = (sign == 0) ? "2147483647" : "2147483648";
	while (s[i] != '\0' && s[i] == max[i])
		i++;
	if (s[i] == '\0' || s[i] < max[i])
		return (1);
	else
		return (0);
}

int			ft_isint(const char *s)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	if (s == NULL)
		return (-1);
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v' || *s == '\f'
		|| *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = 1;
		s++;
	}
	while (ft_isdigit(s[i]) == 1)
	{
		(s[i] == '0') ? s++ : (char *)(unsigned long)i++;
		if (i > 10)
			return (0);
	}
	if (i < 10)
		return (1);
	return (ft_isint2(s, sign));
}
