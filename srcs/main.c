/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:50:11 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/28 14:59:31 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_cub3d	*cub3d;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 2)
		return (1);
	cub3d = malloc(sizeof(t_cub3d));
	if (!cub3d)
		return (1);
	ft_get_info(fd, &cub3d);
	ft_get_map(fd, &cub3d);
	if (ft_check_map(cub3d->map))
		ft_putstr_fd("Map error\n", 1);
	ft_print_struct(cub3d);
	return (0);
}
