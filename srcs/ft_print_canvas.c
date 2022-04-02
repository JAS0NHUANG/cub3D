/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:43:38 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/02 12:15:40 by ifeelbored       ###   ########.fr       */
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

void	init_delta_dist(t_cub3d *cub, double x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * x / S_W - 1;
	ray->dir_x = cub->plr->d_x + cub->plr->pl_x * camera_x;
	ray->dir_y = cub->plr->d_y + cub->plr->pl_y * camera_x;
	ray->delta_dist_x = 1000000;
	ray->delta_dist_y = 1000000;
	if (ray->dir_x != 0)
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y != 0)
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	calcu_texture(t_cub3d *cub, t_ray *ray, t_text *tex, t_my_img *texture)
{
	if (ray->side == 0)
		ray->wall_x = cub->plr->p_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = cub->plr->p_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor((ray->wall_x));
	tex->start = -ray->lign_h / 2 + S_H / 2;
	if (tex->start < 0)
		tex->start = 0;
	tex->end = ray->lign_h / 2 + S_H / 2;
	if (tex->end >= S_H)
		tex->end = S_H - 1;
	tex->tex_x = (int)(ray->wall_x * (double)(texture->w));
	if ((ray->side == 0 && ray->dir_x > 0) || \
		(ray->side == 1 && ray->dir_y < 0))
		tex->tex_x = texture->w - tex->tex_x - 1;
	tex->step = 1.0 * texture->h / ray->lign_h;
	tex->tex_p = (tex->start - S_H / 2 + ray->lign_h / 2) * tex->step;
}

void	print_texture(t_cub3d *cub, t_ray *ray, t_my_img *t_ig, t_my_img *c_ig)
{
	t_text	tex;
	int		y;
	char	*pixel;
	int		tex_y;
	int		color;

	calcu_texture(cub, ray, &tex, t_ig);
	y = 0;
	while (y < S_H)
	{
		if (y < tex.start)
			color = convert_rgb_to_int(cub->info->c);
		else if (y > tex.end)
			color = convert_rgb_to_int(cub->info->f);
		else
		{
			tex_y = (int)tex.tex_p & (t_ig->h - 1);
			color = ((int *)t_ig->img_addr)[(256 / 4) * tex_y + tex.tex_x];
			tex.tex_p += tex.step;
		}
		pixel = c_ig->img_addr + ((int)(y) *c_ig->size) + \
			(int)ray->lp_x * (c_ig->bpp / 8);
		*(unsigned int *)pixel = color;
		y++;
	}
}

int	ft_print_canvas(t_cub3d *cub)
{
	double		x;
	t_my_img	*canvas;
	t_ray		ray;
	t_my_img	*texture;

	canvas = malloc(sizeof(t_my_img));
	canvas->img_ptr = mlx_new_image(cub->mlx_ptr, S_W, S_H);
	canvas->img_addr = mlx_get_data_addr(canvas->img_ptr, \
		&(canvas->bpp), &(canvas->size), &(canvas->endian));
	x = 0.00;
	while (x < S_W)
	{
		init_delta_dist(cub, x, &ray);
		init_side_dist(cub, &ray, (int)(cub->plr->p_x), (int)(cub->plr->p_y));
		dda(cub, &ray, (int)(cub->plr->p_x), (int)(cub->plr->p_y));
		texture = select_texture(cub, ray);
		ray.lp_x = x;
		print_texture(cub, &ray, texture, canvas);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, canvas->img_ptr, 0, 0);
	return (0);
}
