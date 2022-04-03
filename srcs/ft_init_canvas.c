/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_canvas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:19:00 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/02 21:21:42 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_rgb_to_int(int *rgb)
{
	int	color;

	color = rgb[0];
	color = (color << 8) | rgb[1];
	color = (color << 8) | rgb[2];
	return (color);
}

t_my_img	*select_texture(t_cub3d *cub, t_ray ray)
{
	if (ray.side)
	{
		if (ray.dir_y > 0)
			return (&cub->images->no);
		if (ray.dir_y < 0)
			return (&cub->images->so);
	}
	else if (!ray.side)
	{
		if (ray.dir_x > 0)
			return (&cub->images->ea);
		if (ray.dir_x < 0)
			return (&cub->images->we);
	}
	return (0);
}

void	dda(t_cub3d *cub, t_ray *ray, int map_x, int map_y)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->map[map_x][map_y] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->lign_h = (int)(S_H / ray->perp_wall_dist);
}

void	init_side_dist(t_cub3d *cub, t_ray *ray, int map_x, int map_y)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->plr->p_x - map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - cub->plr->p_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->plr->p_y - map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - cub->plr->p_y) * ray->delta_dist_y;
	}
}