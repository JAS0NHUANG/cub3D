#include "cub3d.h"

char	**ft_get_map_array(char *file, int map_lines)
{
	int		fd;
	char	**result_array;
	char	*line;
	int		index;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_error(ERR_OPEN_FILE, NULL);
	result_array = malloc(sizeof(char *) * (map_lines + 1));
	line = NULL;
	index = 0;
	while (get_next_line(fd, &line) > 0)
	{
		result_array[index] = line;
		index++;
	}
	if (line && line[0] != '\0')
	{
		result_array[index] = line;
		index++;
	}
	if (line && line[0] == '\0')
		free(line);
	result_array[index] = NULL;
	return (result_array);
}

int	ft_get_map_lines(char *file)
{
	int		ret;
	int		fd;
	int		line_count;
	char	*line;

	ret = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_error(ERR_OPEN_FILE, NULL);
	line_count = 0;
	line = NULL;
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		line_count++;
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0 && line[0] != '\0')
		line_count++;
	if (fd)
		close(fd);
	if (line)
		free(line);
	return (line_count);
}

void	ft_print_map(t_map *map)
{
	int	index;

	index = 0;
	printf("map: \n");
	while (index < map->height)
	{
		printf("%s\n", map->map_array[index]);
		index++;
	}
}

void	ft_get_map(char *file, t_so_long *so_long)
{
	t_map	*map;
	int		map_lines;

	map = malloc(sizeof(t_map) * 1);
	map_lines = ft_get_map_lines(file);
	if (map_lines == 0)
	{
		free(map);
		return ;
	}
	map->height = map_lines;
	map->map_array = ft_get_map_array(file, map_lines);
	map->width = ft_strlen(map->map_array[0]);
	so_long->map = map;
}
