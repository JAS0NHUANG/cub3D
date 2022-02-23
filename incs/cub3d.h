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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_dot_cub;

#endif
