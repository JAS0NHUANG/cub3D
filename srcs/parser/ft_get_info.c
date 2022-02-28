/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:55:08 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/28 15:35:03 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_get_colors(char **line)
{
	int		i;
	int		j;
	int		*colors;
	int		colors_i;
	char	**holder;

	i = 1;
	colors = malloc(sizeof(int) * 3);
	colors_i = 0;
	while (line[i])
	{
		holder = ft_split(line[i], ',');
		j = 0;
		while (holder[j])
		{
			colors[colors_i] = ft_atoi(holder[j]);
			colors_i++;
			j++;
		}
		i++;
	}
	return (colors);
}

int	ft_put_info_in_cub3d(char **info_array, t_info *info_struct)
{
	char	**line;

	while (*info_array)
	{
		line = ft_split(*info_array, ' ');
		if (ft_strcmp(line[0], "NO") == 0)
			info_struct->no = line[1];
		else if (ft_strcmp(line[0], "SO") == 0)
			info_struct->so = line[1];
		else if (ft_strcmp(line[0], "WE") == 0)
			info_struct->we = line[1];
		else if (ft_strcmp(line[0], "EA") == 0)
			info_struct->ea = line[1];
		else if (ft_strcmp(line[0], "C") == 0)
			info_struct->c = ft_get_colors(line);
		else if (ft_strcmp(line[0], "F") == 0)
			info_struct->f = ft_get_colors(line);
		info_array++;
	}
	return (0);
}

int	ft_init_info(t_cub3d **cub3d)
{
	(*cub3d)->info = malloc(sizeof(t_info));
	if (!(*cub3d)->info)
		return (1);
	(*cub3d)->info->no = NULL;
	(*cub3d)->info->so = NULL;
	(*cub3d)->info->we = NULL;
	(*cub3d)->info->ea = NULL;
	(*cub3d)->info->f = NULL;
	(*cub3d)->info->c = NULL;
	return (0);
}

int	ft_get_info(int fd, t_cub3d **cub3d)
{
	char	*line;
	int		ret;
	int		index;
	char	**info_array;

	info_array = malloc(sizeof(char *) * 7);
	if (!info_array)
		return (1);
	ret = get_next_line(fd, &line);
	index = 0;
	while (ret > 0 && index < 6)
	{
		if (line[0] != '\0')
		{
			info_array[index] = line;
			index++;
		}
		ret = get_next_line(fd, &line);
	}
	info_array[index] = NULL;
	if (ft_init_info(cub3d) != 0)
		return (1);
	ft_put_info_in_cub3d(info_array, (*cub3d)->info);
	return (0);
}
