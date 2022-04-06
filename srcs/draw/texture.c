/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:21:59 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/03 21:41:10 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_cub3d *cub)
{
	cub->imgs->no.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->no, &cub->imgs->no.w, &cub->imgs->no.h);
	cub->imgs->so.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->so, &cub->imgs->so.w, &cub->imgs->so.h);
	cub->imgs->we.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->we, &cub->imgs->we.w, &cub->imgs->we.h);
	cub->imgs->ea.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->ea, &cub->imgs->ea.w, &cub->imgs->ea.h);
	if (!cub->imgs->no.img_ptr || !cub->imgs->so.img_ptr || \
		!cub->imgs->we.img_ptr || !cub->imgs->ea.img_ptr)
		return (1);
	cub->imgs->no.img_addr = mlx_get_data_addr(cub->imgs->no.img_ptr, \
		&cub->imgs->no.bpp, &cub->imgs->no.size, &cub->imgs->no.endian);
	cub->imgs->so.img_addr = mlx_get_data_addr(cub->imgs->so.img_ptr, \
		&cub->imgs->so.bpp, &cub->imgs->so.size, &cub->imgs->so.endian);
	cub->imgs->we.img_addr = mlx_get_data_addr(cub->imgs->we.img_ptr, \
		&cub->imgs->we.bpp, &cub->imgs->we.size, &cub->imgs->we.endian);
	cub->imgs->ea.img_addr = mlx_get_data_addr(cub->imgs->ea.img_ptr, \
		&cub->imgs->ea.bpp, &cub->imgs->ea.size, &cub->imgs->ea.endian);
	if (!cub->imgs->no.img_addr || !cub->imgs->so.img_addr || \
		!cub->imgs->we.img_addr || !cub->imgs->ea.img_addr)
		return (1);
	return (0);
}
