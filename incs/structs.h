#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d
{
	char			**map;
	struct s_info	*info;
	struct s_player	*player;
}	t_cub3d;

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
