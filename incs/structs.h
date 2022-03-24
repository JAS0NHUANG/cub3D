/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:32:52 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/03/25 00:16:48 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cub3d
{
	char			**map;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_images	*images;
	struct s_info	*info;
	struct s_player	*plr;
}	t_cub3d;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_images
{
	t_img		*window_img;
	t_img		*minimap_img;
	t_img		*player_img;
	t_img		*no_texture;
	t_img		*so_texture;
	t_img		*we_texture;
	t_img		*ea_texture;
}	t_images;

typedef struct s_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}	t_info;

typedef struct s_player
{
	double	p_x;//pos
	double	p_y;
	double	d_x;//dir
	double	d_y;
	double	angle;
	double	pl_x; //plane
	double	pl_y;
	double	cam_height;
}	t_player;

typedef struct s_ray
{
}	t_ray;

#endif
