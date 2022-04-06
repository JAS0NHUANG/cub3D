/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:23:58 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/03 23:37:27 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_player(t_cub3d *cb, int key)
{
	double	olddir_x;
	double	oldplane_x;

	if (key == XK_LEFT)
	{
		olddir_x = cb->plr->d_x;
		cb->plr->d_x = cb->plr->d_x * cos(SPD) - cb->plr->d_y * sin(SPD);
		cb->plr->d_y = olddir_x * sin(SPD) + cb->plr->d_y * cos(SPD);
		oldplane_x = cb->plr->pl_x;
		cb->plr->pl_x = cb->plr->pl_x * cos(SPD) - cb->plr->pl_y * sin(SPD);
		cb->plr->pl_y = oldplane_x * sin(SPD) + cb->plr->pl_y * cos(SPD);
	}
	if (key == XK_RIGHT)
	{
		olddir_x = cb->plr->d_x;
		cb->plr->d_x = cb->plr->d_x * cos(-SPD) - cb->plr->d_y * sin(-SPD);
		cb->plr->d_y = olddir_x * sin(-SPD) + cb->plr->d_y * cos(-SPD);
		oldplane_x = cb->plr->pl_x;
		cb->plr->pl_x = cb->plr->pl_x * cos(-SPD) - cb->plr->pl_y * sin(-SPD);
		cb->plr->pl_y = oldplane_x * sin(-SPD) + cb->plr->pl_y * cos(-SPD);
	}
}

int	ft_key_event(int key, t_cub3d *cub3d)
{
	if (key == XK_ESCAPE)
		ft_close(cub3d);
	if (key == XK_W)
		ft_move_w(cub3d);
	if (key == XK_S)
		ft_move_s(cub3d);
	if (key == XK_A)
		ft_move_a(cub3d);
	if (key == XK_D)
		ft_move_d(cub3d);
	if (key == XK_LEFT || key == XK_RIGHT)
		ft_rotate_player(cub3d, key);
	ft_print_canvas(cub3d);
	ft_print_minimap(cub3d, cub3d->imgs);
	return (0);
}
