/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                     config_data.c   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	config_data(t_data *data)
{
	int	i;

	data->space = (((WIDTH <= HEIGHT) ? WIDTH : HEIGHT) - PADDING * 2) /
		(((data->wlen >= data->hlen) ? data->wlen : data->hlen) - 1);
	if (data->space < 1)
		data->space = 1;
	data->dshift = HEIGHT / 2;
	data->rshift = WIDTH / 2;
	data->rotx = ROTX;
	data->roty = ROTY;
	data->rotz = ROTZ;
	if ((data->points = (t_point **)malloc(data->hlen * sizeof(t_point *)))
		== NULL)
		put_error("Mem. Alloc. Error : data->point from config_data\n");
	i = 0;
	while (i < data->hlen)
	{
		if ((data->points[i] = (t_point *)malloc(data->wlen * sizeof(t_point)))
			== NULL)
			put_error("Mem. alloc. Error : data->points[i] from config_data\n");
		i++;
	}
}
