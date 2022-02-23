#include "cub3d.h"

int	ft_get_info(int fd, t_cub3d **cub3d)
{
	(void)cub3d;
	char	*line;
	int		ret;
	int		index;
	char	**info;

	info = malloc(sizeof(char *) * 7);
	if (!info)
		return (1);
	ret = get_next_line(fd, &line);
	index = 0;
	while (ret > 0 && index < 6)
	{
		if (line[0] != '\0')
		{
			info[index] = line;
			index++;
		}
		ret = get_next_line(fd, &line);
	}
	info[index] = NULL;
	return (0);
}
