/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:02:56 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/01 00:17:37 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_w(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	printf("player x: %f, y: %f\n", cub->plr->p_x, cub->plr->p_y);
	plr_t_x = cub->plr->p_x + cub->plr->d_x * MOVE_DIST;
	plr_t_y = cub->plr->p_y + cub->plr->d_y * MOVE_DIST;
	if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

void	ft_move_s(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x - cub->plr->d_x * MOVE_DIST;
	plr_t_y = cub->plr->p_y - cub->plr->d_y * MOVE_DIST;
	if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

void	ft_move_a(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x - cub->plr->d_y * MOVE_DIST;
	plr_t_y = cub->plr->p_y + cub->plr->d_x * MOVE_DIST;
	if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

void	ft_move_d(t_cub3d *cub)
{
	float	plr_t_x;
	float	plr_t_y;

	plr_t_x = cub->plr->p_x + cub->plr->d_y * MOVE_DIST;
	plr_t_y = cub->plr->p_y - cub->plr->d_x * MOVE_DIST;
	if (cub->map[(int)plr_t_x][(int)plr_t_y] != '1')
	{
		cub->map[(int)cub->plr->p_x][(int)cub->plr->p_y] = '0';
		cub->plr->p_x = plr_t_x;
		cub->plr->p_y = plr_t_y;
	}
	else if (cub->map[(int)cub->plr->p_x][(int)plr_t_y] != '1')
		cub->plr->p_y = plr_t_y;
	else if (cub->map[(int)plr_t_x][(int)cub->plr->p_y] != '1')
		cub->plr->p_x = plr_t_x;
}

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
	ft_print_minimap(cub3d);
	return (0);
}
