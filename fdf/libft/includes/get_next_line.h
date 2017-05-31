/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 18:19:52 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 16:33:11 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 32

typedef struct		s_fdlist
{
	int				fd;
	char			*str;
	struct s_fdlist	*next;
}					t_fdlist;

int					get_next_line(const int fd, char **line);

#endif
