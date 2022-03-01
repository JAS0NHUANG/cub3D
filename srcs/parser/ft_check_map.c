/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:51:34 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/01 12:05:59 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_empty(char **map, int x, int y)
{
	if (!map[x][y])
		return (1);
	if (map[x][y])
	{
		if (map[x][y] == ' ')
			return (1);
	}
	return (0);
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
			if (i == 0 || j == 0 || i == array_len -1 || j == str_len - 1)
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					return (ERR_MAP_OPEN);
			}
			else if (map[i][j] == '0')
			{
				if (ft_is_empty(map, i + 1, j) || \
						ft_is_empty(map, i - 1, j) || \
						ft_is_empty(map, i, j + 1) || \
						ft_is_empty(map, i, j - 1))
					return (ERR_MAP_OPEN);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_char(char **map)
{
	int i;
	int j;

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
