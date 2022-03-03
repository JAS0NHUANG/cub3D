#ifndef PARSER_H
# define PARSER_H

int		ft_parser(char *map_file, t_cub3d **cub3d);
int		ft_get_info(int fd, t_cub3d **cub3d);
int		ft_check_info(t_info *info);
int		ft_get_map(int fd, t_cub3d **cub3d);
int		ft_check_map(char **map);
void	ft_set_player(t_cub3d *cub3d);

void	ft_print_struct(t_cub3d *cub_3d);

#endif
