/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:25:25 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 15:03:08 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cp;

	if (lst != NULL)
		cp = ft_lstnew(lst->content, lst->content_size);
	else
		cp = NULL;
	if (cp != NULL)
		cp = f(cp);
	if (cp != NULL && lst->next != NULL)
		cp->next = ft_lstmap(lst->next, f);
	return (cp);
}
