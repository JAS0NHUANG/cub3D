/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:49:27 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/31 23:20:26 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_nbr_array(int *nbr_array, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		ft_putnbr_fd(nbr_array[index], 1);
		if (index != len - 1)
			ft_putstr_fd(", ", 1);
		else
			ft_putstr_fd("\n", 1);
		index++;
	}
	return ;
}

void	ft_print_info(t_info *info)
{
	ft_putstr_fd("\ninfos: \nno:\t", 1);
	ft_putstr_fd(info->no, 1);
	ft_putstr_fd("\nso:\t", 1);
	ft_putstr_fd(info->so, 1);
	ft_putstr_fd("\nwe:\t", 1);
	ft_putstr_fd(info->we, 1);
	ft_putstr_fd("\nea:\t", 1);
	ft_putstr_fd(info->ea, 1);
	ft_putstr_fd("\n", 1);
	if (!info->c || !info->f)
	{
		ft_putstr_fd("c or f not correctly set.\n", 1);
		return ;
	}
	ft_putstr_fd("c:\t", 1);
	ft_print_nbr_array(info->c, 3);
	ft_putstr_fd("f:\t", 1);
	ft_print_nbr_array(info->f, 3);
	return ;
}

void	ft_print_player(t_player *player)
{
	ft_putstr_fd("player pos_x: ", 1);
	printf("%f\n", player->p_x);
	ft_putstr_fd("player pos_y: ", 1);
	printf("%f\n", player->p_y);
	ft_putstr_fd("player dir_x: ", 1);
	printf("%f\n", player->d_x);
	ft_putstr_fd("player dir_y: ", 1);
	printf("%f\n", player->d_y);
}

void	ft_print_struct(t_cub3d *cub_3d)
{
	if (!cub_3d)
	{
		ft_putstr_fd("No cub_3d object.\n", 1);
		return ;
	}
	if (!cub_3d->map)
		ft_putstr_fd("No map.\n", 1);
	else
	{
		ft_putstr_fd("map: \n", 1);
		ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
		ft_print_array(cub_3d->map);
		ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
	}
	if (!cub_3d->info)
		ft_putstr_fd("No info.\n", 1);
	else
		ft_print_info(cub_3d->info);
	if (!cub_3d->plr)
		ft_putstr_fd("No player.\n", 1);
	else
		ft_print_player(cub_3d->plr);
	return ;
}
