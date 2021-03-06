/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:51:34 by jahuang           #+#    #+#             */
/*   Updated: 2022/04/05 16:06:09 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_unsig(const char *str)
{
	int		negatif;
	size_t	result;

	negatif = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negatif = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (*str && (*str < '0' || *str > '9'))
		return (-1);
	if (negatif < 0 && result > 2147483648)
		return (-1);
	if (negatif > 0 && result > 2147483647)
		return (-1);
	return (result * negatif);
}

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
	if (map[x][y] == '0' || map[x][y] == 'N' || map[x][y] == 'S' || \
		map[x][y] == 'E' || map[x][y] == 'W')
	{
		if (!map[x + 1][y] || !map[x - 1] || !map[x][y + 1] || \
			!map[x][y - 1] || !map[x + 1][y + 1] || !map[x + 1][y - 1] || \
			!map[x - 1][y + 1] || !map[x - 1][y - 1])
			return (0);
		if (map[x + 1][y] == ' ' || map[x - 1][y] == ' ' || \
			map[x][y + 1] == ' ' || map[x][y - 1] == ' ' || \
			map[x + 1][y + 1] == ' ' || map[x + 1][y - 1] == ' ' || \
			map[x - 1][y + 1] == ' ' || map[x - 1][y - 1] == ' ')
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
		while (j < str_len)
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
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S' || \
					map[i][j] == 'N')
				player_count++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' && \
				map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != 'S' && \
				map[i][j] != ' ')
				return (ERR_MAP_CHAR);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (ERR_MAP_MULTIPLAYER);
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
