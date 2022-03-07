#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  include "../mlx/mlx.h"
# else
#  include <mlx.h>
# endif

# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "./structs.h"
# include "./enums.h"
# include "./parser.h"
# include "./events.h"
# include "./defines.h"

int		ft_return(int ret_code, t_cub3d *cub3d);
void	ft_free_cub3d(t_cub3d *cub3d);

#endif
