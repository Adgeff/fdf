/******************************************************************************/
/*                                                                            */
/*   #####     #   ######                                             fdf.h   */
/*   #         #   #                                                          */
/*   ###    ####   ###                                                        */
/*   #     #   #   #                                                          */
/*   #      ###    #                                       Geoffrey Argence   */
/*                                                                            */
/******************************************************************************/

#ifndef FDF_H

# define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "libft.h"
#include "mlx.h"

# define HEIGHT 800
# define WIDTH 1200
# define PADDING 50
# define HSPACE 10
# define ROTX 0.0
# define ROTY 0.0
# define ROTZ 0.0
# define ROTSTEP 0.05
# define ZOOMSTEP 10
# define SHIFTSTEP 50

# define PI 3.1415926536

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			**data;
	int			wlen;
	int			hlen;
	int			space;
	int			dshift;
	int			rshift;
	double		rotx;
	double		roty;
	double		rotz;
	t_point		**points;
}				t_data;

void			calcul(t_data *data);
void			config_data(t_data *data);
void			count_args(int fd, t_data *data);
void			get_args(int fd, t_data *data);
void			print(t_data *data);
void			print_lign(void *mlx_ptr, void *win_ptr, t_point a, t_point b);
void			put_error(char *desc);
t_point			rotx(t_point point, double t);
t_point			roty(t_point point, double t);
t_point			rotz(t_point point, double t);

#endif
