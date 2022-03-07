#include "cub3d.h"

int	ft_key_event(int key, t_cub3d *cub3d)
{
	(void)cub3d;
	if (key == XK_Escape)
		ft_close(cub3d);
	if (key == XK_a || key == XK_d || key == XK_w || key == XK_s)
	{
		ft_putstr_fd("move: ", 1);
		ft_putnbr_fd(key, 1);
	}
	if (key == XK_a || key == XK_d || key == XK_w || key == XK_s)
	{
		ft_putstr_fd("move: ", 1);
		ft_putnbr_fd(key, 1);
	}
	if (key == XK_Left || key == XK_Right)
	{
		ft_putstr_fd("rotate: ", 1);
		ft_putnbr_fd(key, 1);
	}
	return (0);
}
