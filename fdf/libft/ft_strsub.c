/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 23:19:39 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:09:31 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*snew;

	if (s == NULL)
		return (NULL);
	i = 0;
	snew = (char *)malloc(len + 1);
	if (snew == NULL)
		return (NULL);
	while (i < len)
	{
		snew[i] = s[start + i];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
