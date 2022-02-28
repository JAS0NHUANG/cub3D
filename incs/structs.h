#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cub3d
{
	char			**map;
	struct s_info	*info;
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

#endif
