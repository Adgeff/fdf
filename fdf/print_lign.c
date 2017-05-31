/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                      print_lign.c   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static void	print_lign_vert(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	int		i;

	i = (int)a.z;
	while (i < (int)b.z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)a.y, i, 0xFFFFFF);
		i++;
	}
}

static void	print_lign_zp(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	double	slope;
	double	ord;
	int		i;

	slope = (b.z - a.z) / (b.y - a.y);
	ord = a.z - slope * a.y;
	i = (int)a.z;
	while (i <= (int)b.z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)((i - ord) / slope), i, 0xFFFFFF);
		i++;
	}
}

static void	print_lign_zm(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	double	slope;
	double	ord;
	int		i;

	slope = (b.z - a.z) / (b.y - a.y);
	ord = a.z - slope * a.y;
	i = (int)a.z;
	while (i >= (int)b.z)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)((i - ord) / slope), i, 0xFFFFFF);
		i--;
	}
}

static void	print_lign_y(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	double	slope;
	double	ord;
	int		i;

	slope = (b.z - a.z) / (b.y - a.y);
	ord = a.z - slope * a.y;
	i = (int)a.y;
	while (i <= (int)b.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, (int)(i * slope + ord), 0xFFFFFF);
		i++;
	}
}

void		print_lign(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
	if ((int)a.y == (int)b.y && a.z - b.z < 0)
		print_lign_vert(mlx_ptr, win_ptr, a, b);
	else if ((int)a.y == (int)b.y)
		print_lign_vert(mlx_ptr, win_ptr, b, a);
	else if ((int)a.y > (int)b.y)
		print_lign(mlx_ptr, win_ptr, b, a);
	else if ((int)(b.z - a.z) > 0 && (int)(b.z - a.z) > (int)(b.y - a.y))
		print_lign_zp(mlx_ptr, win_ptr, a, b);
	else if ((int)(b.z - a.z) < 0 && (int)-(b.z - a.z) > (int)(b.y - a.y))
		print_lign_zm(mlx_ptr, win_ptr, a, b);
	else
		print_lign_y(mlx_ptr, win_ptr, a, b);
}
