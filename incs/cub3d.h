#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_cub3d
{
	struct s_dot_cub	*dot_cub;
}	t_cub3d;

typedef struct s_dot_cub
{
	char	**map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_color;
	char	*c_color;
}	t_dot_cub;

#endif
