/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:21:59 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/01 16:43:22 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_cub3d *cub)
{
	cub->images->no.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->no, &cub->images->no.w, &cub->images->no.h);
	cub->images->so.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->so, &cub->images->so.w, &cub->images->so.h);
	cub->images->we.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->we, &cub->images->we.w, &cub->images->we.h);
	cub->images->ea.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->info->ea, &cub->images->ea.w, &cub->images->ea.h);
	cub->images->no.img_addr = mlx_get_data_addr(cub->images->no.img_ptr, \
		&cub->images->no.bpp, &cub->images->no.size, &cub->images->no.endian);
	cub->images->so.img_addr = mlx_get_data_addr(cub->images->so.img_ptr, \
		&cub->images->so.bpp, &cub->images->so.size, &cub->images->so.endian);
	cub->images->we.img_addr = mlx_get_data_addr(cub->images->we.img_ptr, \
		&cub->images->we.bpp, &cub->images->we.size, &cub->images->we.endian);
	cub->images->ea.img_addr = mlx_get_data_addr(cub->images->ea.img_ptr, \
		&cub->images->ea.bpp, &cub->images->ea.size, &cub->images->ea.endian);
	return (0);
}
