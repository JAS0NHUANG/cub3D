/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:49:21 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/23 15:03:35 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_add_to_array(char **str_array, char *str)
{
	int		array_len;
	char	**new_array;
	int		index;

	array_len = ft_arraylen(str_array);
	new_array = malloc(sizeof(char *) * (array_len + 2));
	index = 0;
	while (str_array && str_array[index] && index < array_len)
	{
		new_array[index] = str_array[index];
		index++;
	}
	new_array[index] = str;
	new_array[index + 1] = NULL;
	free(str_array);
	return (new_array);
}

int	ft_get_map(int fd, t_cub3d **cub3d)
{
	char	*line;
	int		ret;
	int		index;
	char	**map;

	map = NULL;
	ret = get_next_line(fd, &line);
	index = 0;
	while (ret > 0)
	{
		if (line[0] != '\0')
			map = ft_add_to_array(map, line);
		ret = get_next_line(fd, &line);
	}
	(*cub3d)->map = map;
	return (0);
}
