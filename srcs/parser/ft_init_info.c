/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:49:19 by jahuang           #+#    #+#             */
/*   Updated: 2022/04/05 15:52:09 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_info(t_cub3d **cub3d)
{
	(*cub3d)->info = malloc(sizeof(t_info));
	if (!(*cub3d)->info)
		return (ERR_MALLOC);
	(*cub3d)->info->no = NULL;
	(*cub3d)->info->so = NULL;
	(*cub3d)->info->we = NULL;
	(*cub3d)->info->ea = NULL;
	(*cub3d)->info->f = NULL;
	(*cub3d)->info->c = NULL;
	return (0);
}
