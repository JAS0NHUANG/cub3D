/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:50:11 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/21 16:32:01 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}


t_img	*ft_create_tile(t_cub3d *cub3d, unsigned int color, int size)
{
	t_img	*img_holder;
	int		i;
	int		j;
	char	*pixel;

	img_holder = malloc(sizeof(t_img));
	img_holder->img_ptr = mlx_new_image(cub3d->mlx_ptr, size, size);
	img_holder->img_addr = mlx_get_data_addr(img_holder->img_ptr, &(img_holder->bpp), &(img_holder->size), &(img_holder->endian));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel = img_holder->img_addr + (i * img_holder->size) + j * (img_holder->bpp / 8);
			ft_memcpy(pixel, &color, sizeof(unsigned int));
			j++;
		}
		i++;
	}
	return (img_holder);
}

int	ft_print_minimap(t_cub3d *cub3d)
{
	int		i;
	int		j;
	t_img	*mini_map_img;
	t_img	*player_img;
	t_img	*floor_img;
	t_img	*dir_img;

	mini_map_img = ft_create_tile(cub3d, 0x00AAAAAA, 10);
	player_img = ft_create_tile(cub3d, 0x009F0000, 5);
	dir_img = ft_create_tile(cub3d, 0x009F00FF, 5);
	floor_img = ft_create_tile(cub3d, 0x00000000, 10);
	i = 0;
	while (i < ft_arraylen(cub3d->map))
	{
		j = 0;
		while (j < (int)ft_strlen((cub3d->map)[i]))
		{
			if (cub3d->map[i][j] == '1')
				mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, mini_map_img->img_ptr, j * 10 + 20, i * 10 + 20 );
			if (cub3d->map[i][j] == '0')
				mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, floor_img->img_ptr, j * 10 + 20, i * 10 + 20 );
			if (cub3d->map[i][j] == 'W' || cub3d->map[i][j] == 'S' || cub3d->map[i][j] == 'A' || cub3d->map[i][j] == 'D')
			{
				mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, player_img->img_ptr, j * 10 + 20 + 2 , i * 10 + 20 + 2);
			}
			// if (cub3d->map[i][j] == 'W')
			// 	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, player_img->img_ptr, j * 10 + 20 + 2 , i * 10 + 20 + 2);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, dir_img->img_ptr, (cub3d->player->pos_y + cub3d->player->dir_y) * 10 + 20, (cub3d->player->pos_x - cub3d->player->dir_x) * 10 +20);
	printf("cub3d->player->dir_x :%f, cub3d->player->dir_y:%f\n",cub3d->player->dir_x, cub3d->player->dir_y);
	printf("print put image\n");
	return (0);
}

int	ft_run_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		return (ERR_MLX);
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, 1024, 768,
			"cub3d");
	if (!cub3d->win_ptr)
		return (ERR_MLX);
	cub3d->images = malloc(sizeof(t_images));
	cub3d->images->minimap_img = NULL;
	cub3d->images->player_img = NULL;


	ft_print_minimap(cub3d);

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
	if (ac != 2)
		return (ERR_ARGS);
	ret = ft_parser(av[1], &cub3d);
	if (ret != 0)
		return (ft_return(ret, cub3d));

	ft_print_struct(cub3d);
	ft_run_cub3d(cub3d);
	return (ft_return(ret, cub3d));
}
