#include "cub3d.h"

void	ft_set_plane(t_cub3d *cub3d, char player_char)
{
	if (player_char == 'N')
	{
		cub3d->player->plane_x = 0;
		cub3d->player->plane_y = 0.66;
	}
	else if (player_char == 'S')
	{
		cub3d->player->plane_x = 0;
		cub3d->player->plane_y = -0.66;
	}
	else if (player_char == 'W')
	{
		cub3d->player->plane_x = 0.66;
		cub3d->player->plane_y = 0;
	}
	else if (player_char == 'E')
	{
		cub3d->player->plane_x = -0.66;
		cub3d->player->plane_y = 0;
	}
	return ;
}

void	ft_set_direction(t_cub3d *cub3d, char player_char)
{
	if (player_char == 'N')
	{
		cub3d->player->angle = PI / 2;
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
	}
	else if (player_char == 'S')
	{
		cub3d->player->angle = 3 * PI / 2;
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
	}
	else if (player_char == 'W')
	{
		cub3d->player->angle = PI;
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
	}
	else if (player_char == 'E')
	{
		cub3d->player->angle = 0;
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
	}
	return ;
}

void	ft_set_player_info(t_cub3d *cub3d)
{
	int		i;
	int		j;
	char	player_char;

	i = 0;
	while (cub3d->map[i])
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			player_char = cub3d->map[i][j];
			if (player_char == 'N' || player_char == 'S' || \
					player_char == 'E' || player_char == 'W')
			{
				cub3d->player->pos_x = i + 0.5;
				cub3d->player->pos_y = j + 0.5;
				ft_set_direction(cub3d, player_char);
				ft_set_plane(cub3d, player_char);
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
	ft_set_player_info(cub3d);
	/*
	cub3d->player->cam_height =
	*/
}
