/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:42:13 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/01 16:50:30 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_return(int ret_code, t_cub3d *cub3d)
{
	(void)cub3d;
	if (ret_code == ERR_ARGS)
		ft_putstr_fd("Error\nWrong amount of argument(s)\n", 1);
	if (ret_code == ERR_FILE || ret_code == ERR_GNL)
		ft_putstr_fd("Error\nFailed reading the map file\n", 1);
	if (ret_code == ERR_ACCESS)
		ft_putstr_fd("Error\nTexture file not accecible\n", 1);
	if (ret_code == ERR_MALLOC)
		ft_putstr_fd("Error\nFailed allocating memory\n", 1);
	if (ret_code == ERR_INFO)
		ft_putstr_fd("Error\nInvalid information\n", 1);
	if (ret_code == ERR_MAP_NULL)
		ft_putstr_fd("Error\nNo map\n", 1);
	if (ret_code == ERR_MAP_OPEN)
		ft_putstr_fd("Error\nMap not surrounded by walls\n", 1);
	if (ret_code == ERR_MAP_CHAR)
		ft_putstr_fd("Error\nMap contains invalid charecter(s)\n", 1);
	return (ret_code);
}
