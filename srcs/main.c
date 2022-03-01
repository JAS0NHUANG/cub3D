/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:50:11 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/01 17:08:18 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		ret;
	t_cub3d	*cub3d;

	ret = 0;
	if (ac != 2)
		return (ERR_ARGS);
	ret = ft_parser(av[1], &cub3d);
	ft_print_struct(cub3d);
	return (ft_return(ret, cub3d));
}
