/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 17:35:33 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:03:00 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *begin)
{
	int	i;

	i = 0;
	if (begin != NULL)
	{
		i = 1;
		while (begin->next != NULL)
		{
			begin = begin->next;
			i++;
		}
	}
	return (i);
}
