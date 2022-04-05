/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:21:49 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/05 12:09:02 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_dir_img(t_cub3d *cub, t_images *images)
{
	if (images->no.img_ptr)
		mlx_destroy_image(cub->mlx_ptr, images->no.img_ptr);
	if (images->so.img_ptr)
		mlx_destroy_image(cub->mlx_ptr, images->so.img_ptr);
	if (images->we.img_ptr)
		mlx_destroy_image(cub->mlx_ptr, images->we.img_ptr);
	if (images->ea.img_ptr)
		mlx_destroy_image(cub->mlx_ptr, images->ea.img_ptr);
}

void	ft_free_images(t_cub3d *cub, t_images *imgs)
{
	if (!imgs)
		return ;
	if (imgs->canvas)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->canvas->img_ptr);
		free(imgs->canvas);
	}
	if (imgs->plr)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->plr->img_ptr);
		free(imgs->plr);
	}
	if (imgs->minimp)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->minimp->img_ptr);
		free(imgs->minimp);
	}
	if (imgs->dir)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->dir->img_ptr);
		free(imgs->dir);
	}
	if (imgs->flr)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->flr->img_ptr);
		free(imgs->flr);
	}
	free_dir_img(cub, imgs);
	free(imgs);
	return ;
}

void	ft_free_info(t_info *info)
{
	if (info)
	{
		if (info->no)
			free(info->no);
		if (info->so)
			free(info->so);
		if (info->we)
			free(info->we);
		if (info->ea)
			free(info->ea);
		if (info->c)
			free(info->c);
		if (info->f)
			free(info->f);
		free(info);
	}
	return ;
}

void	ft_free_map(char **map)
{
	if (map)
		ft_free_strarray(map);
	return ;
}

void	ft_free_cub3d(t_cub3d *cub3d)
{
	if (cub3d)
	{
		ft_free_map(cub3d->map);
		ft_free_info(cub3d->info);
		if (cub3d->plr)
			free(cub3d->plr);
		ft_free_images(cub3d, cub3d->imgs);
		if (cub3d->win_ptr)
			mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
		if (cub3d->mlx_ptr)
		{
			if (OS)
				mlx_destroy_display(cub3d->mlx_ptr);
			free(cub3d->mlx_ptr);
		}
		free(cub3d);
	}
	return ;
}
