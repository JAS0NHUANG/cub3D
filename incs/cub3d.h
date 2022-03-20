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
/* General functions														  */
/******************************************************************************/
int		ft_return(int ret_code, t_cub3d *cub3d);
void	ft_free_cub3d(t_cub3d *cub3d);

/******************************************************************************/
/* Parser functions															  */
/******************************************************************************/
int		ft_parser(char *map_file, t_cub3d **cub3d);
int		ft_get_info(int fd, t_cub3d **cub3d);
int		ft_check_info(t_info *info);
int		ft_get_map(int fd, t_cub3d **cub3d);
int		ft_check_map(char **map);
void	ft_set_player(t_cub3d *cub3d);

/******************************************************************************/
/* Debug functions															  */
/******************************************************************************/
void	ft_print_struct(t_cub3d *cub_3d);
int		ft_print_minimap(t_cub3d *cub_3d);

/******************************************************************************/
/* MLX Event functions														  */
/******************************************************************************/
int	ft_key_event(int key, t_cub3d *cub3d);
int	ft_close(t_cub3d *cub3d);

#endif
