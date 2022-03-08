#include "cub3d.h"

void	ft_set_position(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S' || \
					cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')
			{
				cub3d->player->pos_x = i + 0.5;
				cub3d->player->pos_y = j + 0.5;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	ft_set_player(t_cub3d *cub3d)
{
	cub3d->player = malloc(sizeof(t_player));
	if (!(cub3d->player))
		return ;
	ft_set_position(cub3d);
	/*
	ft_set_direction(cub3d);
	ft_set_plane(cub3d);
	cub3d->player->cam_height =
	*/
}
