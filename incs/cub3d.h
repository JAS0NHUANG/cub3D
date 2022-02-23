#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

enum	map_err
{
	ERR_MAP_NULL = 1,
	ERR_MAP_OPEN,
};

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
	char	*f;
	char	*c;
}	t_info;

int	ft_get_info(int fd, t_cub3d **cub3d);
int	ft_get_map(int fd, t_cub3d **cub3d);
int	ft_check_map(char **map);

#endif
