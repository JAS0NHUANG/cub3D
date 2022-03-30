/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:32:52 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/03/30 18:18:16 by ifeelbored       ###   ########.fr       */
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

typedef struct s_my_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
	int		w;
	int		h;
	// int			x;
	// int			y;
}	t_my_img;

// typedef struct s_texture
// {
// 	int			x;
// 	int			y;
// 	t_img		*img;
// }			t_texture;

typedef struct s_images
{
	t_my_img		*window_img;
	t_my_img		*minimap_img;
	t_my_img		*player_img;
	t_my_img		no;
	t_my_img		so;
	t_my_img		we;
	t_my_img		ea;
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
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	//int			real_line_h;
	int			side;
	double		wall_x;
}	t_ray;
#endif
