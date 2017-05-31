/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 23:29:39 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:07:35 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcat;
	size_t	s1len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	strcat = (char *)malloc(s1len + ft_strlen(s2) + 1);
	if (strcat == NULL)
		return (NULL);
	ft_strcpy(strcat, s1);
	ft_strcpy(strcat + s1len, s2);
	return (strcat);
}
