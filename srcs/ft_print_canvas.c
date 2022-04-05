/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:43:38 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/05 11:58:49 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_print_canvas(t_cub3d *cub)
{
	double		x;
	t_my_img	*canvas;
	t_ray		ray;
	t_my_img	*texture;

	if (!(cub->imgs->canvas))
	{
		canvas = malloc(sizeof(t_my_img));
		canvas->img_ptr = mlx_new_image(cub->mlx_ptr, S_W, S_H);
		canvas->img_addr = mlx_get_data_addr(canvas->img_ptr, \
			&(canvas->bpp), &(canvas->size), &(canvas->endian));
	}
	else
		canvas = cub->imgs->canvas;
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
	cub->imgs->canvas = canvas;
}
