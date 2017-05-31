/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 23:41:05 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:09:38 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	endspc;
	char	*strim;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (i-- == 0)
		return (ft_strdup(""));
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
		i--;
	if (i == 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		return (ft_strdup(""));
	endspc = ft_strlen(s) - (i + 1);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	strim = (char *)malloc(ft_strlen(s) - i - endspc + 1);
	if (strim == NULL)
		return (NULL);
	strim = ft_strncpy(strim, s + i, ft_strlen(s) - i - endspc);
	strim[ft_strlen(s) - i - endspc] = '\0';
	return (strim);
}
