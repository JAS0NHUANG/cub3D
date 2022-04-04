/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:55:08 by jahuang           #+#    #+#             */
/*   Updated: 2022/04/04 22:10:08 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_colors_lp(char	**holder, int **colors, int	*colors_i)
{
	int	j;

	j = 0;
	while (holder[j])
	{
		(*colors)[*colors_i] = ft_atoi_unsig(holder[j]);
		if (*colors_i >= 4 || (*colors)[*colors_i] > 255 || \
			(*colors)[*colors_i] < 0)
		{
			//ft_free_strarray(holder);
			//free(*colors);
			return (1);
		}
		(*colors_i) = (*colors_i) + 1;
		if ((*colors_i) == 4)
			return (1);
		j++;
	}
	return (0);
}
void printf_arr(char **s)
{
	int i;

	i =0;
	while (s[i])
	{
		printf("s:%s\n", s[i]);
		i++;
	}
	printf("end\n");
}

int	*ft_get_colors(char **line)
{
	int		i;
	int		*colors;
	int		colors_i;
	char	**holder;

	i = 0;
	colors = malloc(sizeof(int) * 3);
	colors_i = 0;
	while (line[++i])
	{
		holder = ft_split(line[i], ',');
		//printf("line[i], holdre[0]:|%s|, |%s|\n", line[i],holder[0]);
		if ((i != 3 && line[i][ft_strlen(line[i]) - 1] != ',' && !holder[1]) || \
			!holder[0])
		{
			ft_free_strarray(holder);
			free(colors);
			return (NULL);
		}
		if (ft_get_colors_lp(holder, &colors, &colors_i))
		{
			ft_free_strarray(holder);
			free(colors);
			return (NULL);
		}
		//free(holder);
		ft_free_strarray(holder);
		if (!colors)
			return (NULL);
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
			info_struct->no = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "SO") == 0)
			info_struct->so = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "WE") == 0)
			info_struct->we = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "EA") == 0)
			info_struct->ea = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "C") == 0)
			info_struct->c = ft_get_colors(line);
		else if (ft_strcmp(line[0], "F") == 0)
			info_struct->f = ft_get_colors(line);
		info_array++;
		ft_free_strarray(line);
	}
	if (!info_struct->c || !info_struct->f)
		return (1);
	return (0);
}

int	ft_init_info(t_cub3d **cub3d)
{
	(*cub3d)->info = malloc(sizeof(t_info));
	if (!(*cub3d)->info)
		return (ERR_MALLOC);
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
	int		index;
	char	**info_array;

	info_array = malloc(sizeof(char *) * 7);
	if (!info_array)
		return (ERR_MALLOC);
	index = 0;
	while (get_next_line(fd, &line) > 0 && index < 6)
	{
		if (line && line[0] != '\0')
		{
			info_array[index] = line;
			index++;
		}
	}
	info_array[index] = NULL;
	if (ft_init_info(cub3d) != 0 || ft_put_info_in_cub3d(info_array, (*cub3d)->info))
	{
		ft_free_strarray(info_array);
		return (ERR_INFO);
	}
	return (ft_check_info((*cub3d)->info));
}