/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 17:38:33 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:02:02 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddend(t_list *begin, t_list *new)
{
	if (begin != NULL)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = new;
	}
}
