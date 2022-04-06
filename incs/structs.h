/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:32:52 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/03 23:12:29 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cub3d
{
	char			**map;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_images	*imgs;
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
}	t_my_img;

typedef struct s_images
{
	t_my_img		*canvas;
	t_my_img		*minimp;
	t_my_img		*plr;
	t_my_img		*dir;
	t_my_img		*flr;
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
	double	p_x;
	double	p_y;
	double	d_x;
	double	d_y;
	double	pl_x;
	double	pl_y;
}	t_player;

typedef struct s_ray
{
	double		lp_x;
	double		dir_x;
	double		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_x;
	int			lign_h;
}	t_ray;

typedef struct s_text
{
	int		start;
	int		end;
	int		tex_x;
	double	step;
	double	tex_p;
}	t_text;
#endif
