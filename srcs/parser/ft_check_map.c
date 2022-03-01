/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:51:34 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/01 16:29:12 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_surrounded(char **map, int x, int y, int array_len)
{
	int	str_len;

	if (!map[x])
		return (0);
	str_len = ft_strlen(map[x]);
	if (x == 0 || y == 0 || x == array_len -1 || y == str_len - 1)
	{
		if (map[x][y] != '1' && map[x][y] != ' ')
			return (0);
	}
	if (map[x][y] == '0')
	{
		if (!map[x + 1][y] || !map[x - 1] || !map[x][y + 1] || !map[x][y - 1])
			return (0);
		if (map[x + 1][y] == ' ' || map[x - 1][y] == ' ' || \
				map[x][y + 1] == ' ' || map[x][y - 1] == ' ')
			return (0);
	}
	return (1);
}

static int	ft_check_close(char **map, int array_len)
{
	int	i;
	int	j;
	int	str_len;

	i = 0;
	while (i < array_len)
	{
		j = 0;
		str_len = ft_strlen(map[i]);
		while (j < str_len - 1)
		{
			if (!ft_is_surrounded(map, i, j, array_len))
				return (ERR_MAP_OPEN);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' && \
				map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S' && \
				map[i][j] != ' ')
				return (ERR_MAP_CHAR);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char **map)
{
	int	array_len;
	int	ret;

	if (!map)
		return (ERR_MAP_NULL);
	array_len = ft_arraylen(map);
	ret = 0;
	ret = ft_check_char(map);
	if (ret != 0)
		return (ret);
	ret = ft_check_close(map, array_len);
	if (ret != 0)
		return (ret);
	return (0);
}
