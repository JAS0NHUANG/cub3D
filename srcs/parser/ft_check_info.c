/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:12:49 by jahuang           #+#    #+#             */
/*   Updated: 2022/04/01 12:25:40 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr_ex(const char *s, int c)
{
	unsigned char	*ch_s;

	ch_s = (unsigned char *)s;
	while (*ch_s)
	{
		if ((*ch_s) == (unsigned char)c)
			return ((char *)ch_s);
		ch_s++;
	}
	if ((*ch_s) == '\0' && c == '\0')
		return ((char *)ch_s);
	return (0);
}

int	check_extension(char *path)
{
	char	*str;

	str = ft_strchr_ex(path, '.');
	if (!str)
		return (1);
	str++;
	printf("str:%s\n", str);
	if (ft_strcmp(str, "xpm"))
		return (1);
	return (0);
}

int	ft_check_access(t_info *info)
{
	int	fd;

	if (!info->no || !info->so || !info->we || !info->ea)
		return (ERR_ACCESS);
	if (check_extension(info->no) || check_extension(info->so) || \
		check_extension(info->we) || check_extension(info->ea))
		return (ERR_ACCESS);
	fd = open(info->no, O_RDONLY);
	if (fd <= 0)
		return (ERR_ACCESS);
	close(fd);
	fd = open(info->so, O_RDONLY);
	if (fd <= 0)
		return (ERR_ACCESS);
	close(fd);
	fd = open(info->we, O_RDONLY);
	if (fd <= 0)
		return (ERR_ACCESS);
	close(fd);
	fd = open(info->ea, O_RDONLY);
	if (fd <= 0)
		return (ERR_ACCESS);
	close(fd);
	return (0);
}

int	ft_check_colors(t_info *info)
{
	int	index;

	index = 0;
	while (index < 3)
	{
		if (info->c[index] < 0 || info->c[index] > 255)
			return (1);
		index++;
	}
	index = 0;
	while (index < 3)
	{
		if (info->f[index] < 0 || info->f[index] > 255)
			return (1);
		index++;
	}
	if (info->c[index])
		return (1);
	return (0);
}

int	ft_check_info(t_info *info)
{
	if (!info->no || !info->so || !info->we || !info->ea || \
			!info->f || !info->c)
		return (ERR_INFO);
	if (ft_check_access(info) != 0)
		return (ERR_ACCESS);
	if (ft_check_colors(info) != 0)
		return (ERR_INFO);
	return (0);
}
