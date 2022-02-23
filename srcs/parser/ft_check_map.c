#include "cub3d.h"

static int	ft_is_empty(char **map, int x, int y)
{
	if (!map[x][y])
		return (1);
	if (map[x][y])
	{
		if(map[x][y] == ' ')
			return (1);
	}
	return (0);
}

static int	ft_check_line(char **map, int index, int array_len)
{
	int	j;
	int	str_len;

	j = 0;
	str_len = ft_strlen(map[index]);
	while (map[index][j])
	{
		if (index == 0 || index == array_len - 1 || j == 0 || j == str_len - 1)
		{
			if (map[index][j] != ' ' && map[index][j] != '1')
				return (ERR_MAP_OPEN);
		}
		if (map[index][j] == '0')
		{
			if (ft_is_empty(map, index + 1, j) || \
					ft_is_empty(map, index - 1, j) || \
					ft_is_empty(map, index, j + 1) || \
					ft_is_empty(map, index, j - 1))
				return (ERR_MAP_OPEN);
		}
		j++;
	}
	return (0);
}

int	ft_check_map(char **map)
{
	int	i;
	int	array_len;
	int	ret;

	if (!map)
		return (ERR_MAP_NULL);
	i = 0;
	array_len = ft_arraylen(map);
	ret = 0;
	while (i < array_len)
	{
		ret = ft_check_line(map, i, array_len);
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}
