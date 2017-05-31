/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:22:40 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 14:32:05 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2, int f)
{
	char	*strcat;

	if ((strcat = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	if (f == 1 || f >= 3)
		free(s1);
	if (f == 2 || f >= 3)
		free(s2);
	return (strcat);
}
