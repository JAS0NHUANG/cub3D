#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d
{
	char			**map;
	struct s_info	*info;
	struct s_player	*player;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_images	*images;
}	t_cub3d;

typedef struct s_images
{
	t_img		window_img;
	t_img		no_texture;
	t_img		so_texture;
	t_img		we_texture;
	t_img		ea_texture;
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
	char	direction;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_height;
	double	move_dist;
	double	rot_speed;
}	t_player;

#endif
