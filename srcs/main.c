/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:50:11 by jahuang           #+#    #+#             */
/*   Updated: 2022/04/05 15:47:26 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_run_cub3d(t_cub3d *cub3d)
{
	if (!cub3d->mlx_ptr)
		return (ERR_MLX);
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, S_W, S_H,
			"cub3d");
	if (!cub3d->win_ptr)
		return (ERR_MLX);
	cub3d->imgs->canvas = NULL;
	cub3d->imgs->minimp = NULL;
	cub3d->imgs->plr = NULL;
	cub3d->imgs->dir = NULL;
	cub3d->imgs->flr = NULL;
	ft_print_canvas(cub3d);
	ft_print_minimap(cub3d, cub3d->imgs);
	mlx_hook(cub3d->win_ptr, 2, 1l << 0, &ft_key_event, cub3d);
	mlx_hook(cub3d->win_ptr, 17, 1l << 0, &ft_close, cub3d);
	mlx_loop(cub3d->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	int		ret;
	t_cub3d	*cub3d;

	ret = -1;
	cub3d = NULL;
	if (ac != 2)
		return (ft_return(ERR_ARGS, cub3d));
	ret = ft_parser(av[1], &cub3d);
	if (ret != 0)
		return (ft_return(ret, cub3d));
	cub3d->imgs = malloc(sizeof(t_images));
	cub3d->mlx_ptr = mlx_init();
	if (init_texture(cub3d))
		return (ft_return(ERR_INFO, cub3d));
	if (ft_run_cub3d(cub3d))
		return (ft_return(ERR_INFO, cub3d));
	return (0);
}
