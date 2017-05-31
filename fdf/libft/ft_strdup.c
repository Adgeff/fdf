/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:26:11 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:07:05 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s1cpy;

	s1cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (s1cpy == NULL)
		return (NULL);
	ft_strcpy(s1cpy, s1);
	return (s1cpy);
}
