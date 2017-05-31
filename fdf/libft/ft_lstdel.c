/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:52:04 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:02:35 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*delelem;

	delelem = *alst;
	while (delelem != NULL)
	{
		delelem = delelem->next;
		ft_lstdelone(alst, del);
		*alst = delelem;
	}
}
