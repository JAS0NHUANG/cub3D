#include "cub3d.h"

void	ft_set_plane(t_cub3d *cub3d, char player_char)
{
	if (player_char == 'N')
	{
		cub3d->plr->pl_x = 0;
		cub3d->plr->pl_y = 0.66;
	}
	else if (player_char == 'S')
	{
		cub3d->plr->pl_x = 0;
		cub3d->plr->pl_y = -0.66;
	}
	else if (player_char == 'W')
	{
		cub3d->plr->pl_x = 0.66;
		cub3d->plr->pl_y = 0;
	}
	else if (player_char == 'E')
	{
		cub3d->plr->pl_x = -0.66;
		cub3d->plr->pl_y = 0;
	}
	return ;
}

void	ft_set_direction(t_cub3d *cub3d, char player_char)
{
	if (player_char == 'N')
	{
		cub3d->plr->d_x = -1;
		cub3d->plr->d_y = 0;
	}
	else if (player_char == 'S')
	{
		cub3d->plr->d_x = 1;
		cub3d->plr->d_y = 0;
	}
	else if (player_char == 'W')
	{
		cub3d->plr->d_x = 0;
		cub3d->plr->d_y = -1;
	}
	else if (player_char == 'E')
	{
		cub3d->plr->d_x = 0;
		cub3d->plr->d_y = 1;
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
				cub3d->plr->p_x = i + 0.5;
				cub3d->plr->p_y = j + 0.5;
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
	cub3d->plr = malloc(sizeof(t_player));
	if (!(cub3d->plr))
		return ;
	ft_set_player_info(cub3d);
	/*
	cub3d->plr->cam_height =
	*/
}
