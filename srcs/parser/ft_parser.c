/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:54:30 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/01 17:21:27 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file_type(char *map_file)
{
	int		str_len;
	char	*holder;

	str_len = ft_strlen(map_file);
	if (str_len <= 4)
		return (ERR_FILE);
	holder = map_file;
	holder += str_len - 4;
	if (ft_strcmp(holder, ".cub") != 0)
		return (ERR_FILE);
	return (0);
}

int	ft_parser(char *map_file, t_cub3d **cub3d)
{
	int		fd;
	int		ret;

	ret = 0;
	if (ft_check_file_type(map_file) != 0)
		return (ERR_FILE);
	fd = open(map_file, O_RDONLY);
	if (fd <= 2)
		return (ERR_FILE);
	*cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
		return (ERR_MALLOC);
	(*cub3d)->info = NULL;
	(*cub3d)->map = NULL;
	ft_get_info(fd, cub3d);
	ret = ft_check_info((*cub3d)->info);
	if (ret != 0)
		return (ret);
	ft_get_map(fd, cub3d);
	ret = ft_check_map((*cub3d)->map);
	if (ret != 0)
		return (ret);
	return (0);
}
