/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                        get_args.c   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static int	*get_line_args(char *str, int nbr)
{
	int		i;
	int		j;
	int		*args;

	if ((args = (int*)malloc(nbr * sizeof(int))) == NULL)
		put_error("Mem. Alloc. Error : args from get_line_args\n");
	j = 0;
	while (j < nbr)
	{
		args[j] = 0;
		j++;
	}
	if (str == NULL)
		return (args);
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			args[j] = ft_atoi(str + i) * HSPACE;
			j++;
		}
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (args);
}

void		get_args(int fd, t_data *data)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	if ((data->data = (int **)malloc(data->hlen * sizeof(int *))) == NULL)
		put_error("Mem. Alloc. Error : data->data from get_args\n");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data->data[i] = get_line_args(line, data->wlen);
		free(line);
		i++;
	}
	if (ret == -1)
		put_error("Error reading file : get_args\n");
}
