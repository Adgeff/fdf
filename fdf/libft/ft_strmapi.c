/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:50:38 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:08:04 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scpy;
	size_t	i;

	if (s == NULL)
		return (NULL);
	scpy = (char *)malloc(ft_strlen(s) + 1);
	if (scpy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		scpy[i] = f((unsigned int)i, s[i]);
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
