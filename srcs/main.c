#include "cub3d.h"

int	ft_get_map(int fd, t_cub3d **cub3d)
{
	(void)cub3d;
	char	*line;
	int		ret;
	int		index;
	char	**texture_and_color;

	texture_and_color = malloc(sizeof(char *) * 7);
	if (!texture_and_color)
		return (1);
	ret = get_next_line(fd, &line);
	index = 0;
	while (ret > 0)
	{
		if (line[0] != '\0')
			texture_and_color[index] = line;
		ret = get_next_line(fd, &line);
		index++;
	}
}

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
	ft_get_map(fd, &cub3d);
}
