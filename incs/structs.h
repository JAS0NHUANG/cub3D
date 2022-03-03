#ifndef STRUCT_H
# define STRUCT_H

# include <mlx.h>

typedef struct s_cub3d
{
	char			**map;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_images	*images;
	struct s_info	*info;
	struct s_player	*player;
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
}	t_player;

#endif
