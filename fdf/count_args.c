/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                      count_args.c   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static int	count_line_args(char *str)
{
	int		args;
	int		i;

	if (str == NULL)
		return (0);
	args = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			args++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (args);
}

void		count_args(int fd, t_data *data)
{
	char	*line;
	int		ret;
	int		max;

	data->wlen = 0;
	data->hlen = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((max = count_line_args(line)) > data->wlen)
			data->wlen = max;
		free(line);
		data->hlen++;
	}
	if (ret == -1)
		put_error("Error reading file : count_args\n");
	if (data->wlen < 2 || data->hlen < 2)
		put_error("Error : Map is too small\n");
}
