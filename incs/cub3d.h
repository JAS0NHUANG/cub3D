/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:28:06 by ifeelbored        #+#    #+#             */
/*   Updated: 2022/04/05 12:59:05 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  include "../mlx/mlx.h"
# else
#  include "../mlx_mac/mlx.h"
# endif

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "../libft/libft.h"
# include "./structs.h"
# include "./defines.h"

/******************************************************************************/
/* Parser functions															  */
/******************************************************************************/
int			ft_parser(char *map_file, t_cub3d **cub3d);
int			ft_get_info(int fd, t_cub3d **cub3d);
int			ft_check_info(t_info *info);
int			ft_get_map(int fd, t_cub3d **cub3d);
int			ft_check_map(char **map);
int			ft_set_player(t_cub3d *cub3d);
int			ft_atoi_unsig(const char *str);

/******************************************************************************/
/* Draw functions	    													  */
/******************************************************************************/
int			ft_print_minimap(t_cub3d *cub_3d, t_images *ig);
int			convert_rgb_to_int(int *rgb);
t_my_img	*select_texture(t_cub3d *cub, t_ray ray);
void		dda(t_cub3d *cub, t_ray *ray, int map_x, int map_y);
void		init_side_dist(t_cub3d *cub, t_ray *ray, int map_x, int map_y);
void		ft_print_canvas(t_cub3d *cub);

/******************************************************************************/
/* MLX Event functions														  */
/******************************************************************************/
int			ft_key_event(int key, t_cub3d *cub3d);
int			ft_close(t_cub3d *cub3d);
int			init_texture(t_cub3d *cub);
void		ft_move_w(t_cub3d *cub);
void		ft_move_s(t_cub3d *cub);
void		ft_move_a(t_cub3d *cub);
void		ft_move_d(t_cub3d *cub);

/******************************************************************************/
/* Util functions    														  */
/******************************************************************************/
int			ft_return(int ret_code, t_cub3d *cub3d);
void		ft_free_cub3d(t_cub3d *cub3d);

/******************************************************************************/
/* Debug functions															  */
/******************************************************************************/
void		ft_print_struct(t_cub3d *cub_3d);
#endif
