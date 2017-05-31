/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                           print.c   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	print(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->hlen)
	{
		i = 0;
		while (i < data->wlen)
		{
			if (i + 1 < data->wlen)
				print_lign(data->mlx_ptr, data->win_ptr, data->points[j][i],
					data->points[j][i + 1]);
			if (j + 1 < data->hlen)
			{
				print_lign(data->mlx_ptr, data->win_ptr, data->points[j][i],
					data->points[j + 1][i]);
			}
			i++;
		}
		j++;
	}
}
