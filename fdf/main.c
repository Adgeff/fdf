/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                            main.c   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

int			key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 ||
		keycode == 12 || keycode == 14 || keycode == 126 || keycode == 125 ||
		keycode == 124 || keycode == 123 || keycode == 44 || keycode == 24 ||
		keycode == 15)
	{
		if (keycode == 13)
			data->roty = data->roty + ROTSTEP;
		else if (keycode == 1)
			data->roty = data->roty - ROTSTEP;
		else if (keycode == 0)
			data->rotx = data->rotx - ROTSTEP;
		else if (keycode == 2)
			data->rotx = data->rotx + ROTSTEP;
		else if (keycode == 12)
			data->rotz = data->rotz - ROTSTEP;
		else if (keycode == 14)
			data->rotz = data->rotz + ROTSTEP;
		else if (keycode == 126)
			data->dshift = data->dshift + SHIFTSTEP;
		else if (keycode == 125)
			data->dshift = data->dshift - SHIFTSTEP;
		else if (keycode == 124)
			data->rshift = data->rshift - SHIFTSTEP;
		else if (keycode == 123)
			data->rshift = data->rshift + SHIFTSTEP;
		else if (keycode == 44)
			data->space = data->space + ZOOMSTEP;
		else if (keycode == 24 && data->space - ZOOMSTEP >= 1)
			data->space = data->space - ZOOMSTEP;
		else if (keycode == 15)
			config_data(data);
		calcul(data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		print(data);
	}
		if (keycode == 53)
			exit(EXIT_SUCCESS);
	return (1);
}

static void	fdf(t_data *data, char *name)
{
	calcul(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, name);
	print(data);
	mlx_key_hook(data->win_ptr, &key_hook, data);
	mlx_loop(data->mlx_ptr);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			put_error("Error opening file\n");
		if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
			put_error("Mem. Alloc. Error : data from main\n");
		count_args(fd, data);
		if (close(fd) == -1)
			put_error("Error closing file\n");
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			put_error("Error opening file (2)\n");
		get_args(fd, data);
		if (close(fd) == -1)
			put_error("Error closing file (2)\n");
		config_data(data);
		fdf(data, argv[1]);
	}
	else
		put_error("Invalid argument number\n");
	return (0);
}
