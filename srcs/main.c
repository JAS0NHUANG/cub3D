#include "cub3d.h"

int	main(int ac, char **av)
{
	(void)ac;
	int		fd;
	int		ret;
	char	*line;

	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		printf("%s\n", line);
		free(line);
		ret = get_next_line(fd, &line);
	}
}
