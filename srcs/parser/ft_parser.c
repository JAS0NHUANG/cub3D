/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:54:30 by jahuang           #+#    #+#             */
/*   Updated: 2022/04/03 23:03:45 by ifeelbored       ###   ########.fr       */
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
	(*cub3d)->info = NULL;
	(*cub3d)->map = NULL;
	(*cub3d)->mlx_ptr = NULL;
	(*cub3d)->win_ptr = NULL;
	(*cub3d)->imgs = NULL;
	(*cub3d)->plr = NULL;
	ret = ft_get_info(fd, cub3d);
	if (ret != 0)
		return (ret);
	ret = ft_get_map(fd, cub3d);
	if (ret != 0)
		return (ret);
	if (ft_set_player(*cub3d))
		return (ERR_MALLOC);
	return (0);
}
