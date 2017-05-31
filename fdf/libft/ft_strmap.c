/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:41:18 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:07:57 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*scpy;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	scpy = (char *)malloc(ft_strlen(s) + 1);
	if (scpy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		scpy[i] = f(s[i]);
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
