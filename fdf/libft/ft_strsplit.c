/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:44:15 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:09:17 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		wnbrc(char const *s, char c)
{
	size_t			i;
	size_t			size;

	i = 0;
	size = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] != c && s[i] != '\0')
				size++;
			while (s[i] != c && s[i] != '\0')
				i++;
			while (s[i] == c)
				i++;
		}
	return (size);
}

static char			*strtoc(char const *s, char c)
{
	size_t			i;
	char			*str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	str = (char *)malloc(i + 1);
	str = ft_strncpy(str, s, i);
	str[i] = '\0';
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	size_t			size;
	size_t			i1;
	size_t			i2;

	size = wnbrc(s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (s == NULL || tab == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (i2 < size)
	{
		if (s[i1] != c && s[i1] != '\0')
		{
			tab[i2] = strtoc(s + i1, c);
			i2++;
		}
		while (s[i1] != c && s[i1] != '\0')
			i1++;
		while (s[i1] == c)
			i1++;
	}
	tab[size] = NULL;
	return (tab);
}
