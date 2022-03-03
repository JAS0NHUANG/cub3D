#include "cub3d.h"

int	ft_close(t_cub3d *cub3d)
{
	ft_free_cub3d(cub3d);
	exit(0);
}
