#include "cub3d.h"

int	main(int ac, char **av)
{
	(void)ac;
	int		fd;
	t_cub3d	*cub3d;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
	cub3d = malloc(sizeof(t_cub3d) * 1);
	ft_get_info(fd, &cub3d);
	ft_get_map(fd, &cub3d);
	if (ft_check_map(cub3d->map))
		ft_putstr_fd("Map error\n", 1);
	ft_print_array(cub3d->map);
	return (0);
}
