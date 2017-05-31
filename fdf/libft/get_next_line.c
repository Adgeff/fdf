/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 18:19:15 by gargence          #+#    #+#             */
/*   Updated: 2016/09/20 16:27:23 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fdlist		*find(t_fdlist **begin, int fd)
{
	t_fdlist		*list;

	list = *begin;
	while (list != NULL && list->fd != fd)
		list = list->next;
	if (list == NULL)
	{
		if ((list = (t_fdlist *)malloc(sizeof(t_fdlist))) == NULL)
			return (NULL);
		list->fd = fd;
		list->str = NULL;
		list->next = *begin;
		*begin = list;
	}
	return (list);
}

static int			old_read(t_fdlist *current, char **line)
{
	size_t			i;
	char			*tmp;
	int				ret;

	if (current->str == NULL)
		return (0);
	i = 0;
	while (current->str[i] != '\n' && current->str[i] != '\0')
		i++;
	ret = 0;
	if (current->str[i] == '\n')
		ret = 1;
	if ((*line = (char *)malloc(i + 1)) == NULL)
		return (-1);
	ft_strncpy(*line, current->str, i);
	(*line)[i] = '\0';
	tmp = NULL;
	if (current->str[i] == '\n' && current->str[i + 1] != '\0')
		if ((tmp = ft_strdup(current->str + i + 1)) == NULL)
			return (-1);
	free(current->str);
	current->str = tmp;
	return (ret);
}

static int			read_loop(char *buf, ssize_t ret,
	t_fdlist *current, char **line)
{
	size_t			i;
	char			*tmp;

	buf[ret] = '\0';
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if ((tmp = (char *)malloc(ft_strlen(*line) + i + 1)) == NULL)
		return (-1);
	if (*line != NULL)
		ft_strcpy(tmp, *line);
	ft_strncat(tmp, buf, i);
	tmp[ft_strlen(*line) + i] = '\0';
	free(*line);
	*line = tmp;
	if (buf[i] == '\n')
	{
		if (buf[i + 1] != '\0' &&
			(current->str = ft_strdup(buf + i + 1)) == NULL)
			return (-1);
		else
			return (1);
	}
	return (0);
}

static int			new_read(t_fdlist *current, char **line)
{
	ssize_t			ret;
	char			*buf;
	ssize_t			ret_rdloop;

	if ((buf = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	while ((ret = read(current->fd, buf, BUFF_SIZE)) > 0)
	{
		if ((ret_rdloop = read_loop(buf, ret, current, line)) != 0)
		{
			free(buf);
			return (ret_rdloop);
		}
	}
	free(buf);
	if (ret == -1)
		return (-1);
	return ((ret == 0 && *line == NULL) ? 0 : 1);
}

int					get_next_line(const int fd, char **line)
{
	static t_fdlist	*begin = NULL;
	t_fdlist		*current;
	int				ret_old_read;

	if ((fd <= 2 && fd != 0) || line == NULL)
		return (-1);
	*line = NULL;
	if ((current = find(&begin, fd)) == NULL)
		return (-1);
	ret_old_read = old_read(current, line);
	if (ret_old_read == 1 || ret_old_read == -1)
		return (ret_old_read);
	return (new_read(current, line));
}
