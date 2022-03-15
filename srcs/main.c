/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:50:11 by jahuang           #+#    #+#             */
/*   Updated: 2022/03/15 18:09:54 by jahuang          ###   ########.fr       */
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

int	ft_print_minimap(t_cub3d *cub3d)
{
	int		i;
	int		j;
	t_img	*mini_map_img;
	unsigned int color = 0x00FF00;
	char	*pixel;

	printf("ok here\n");
	if(cub3d)
	{
		mini_map_img = malloc(sizeof(mini_map_img));
		printf("ok in\n");
	}
	printf("w: %d, h: %d\n",(int)ft_strlen((cub3d->map)[0]), ft_arraylen(cub3d->map));

	if (cub3d->map)
	{
		printf("ok map\n");
		mini_map_img->img_ptr = mlx_new_image(cub3d->mlx_ptr, ft_strlen((cub3d->map)[0]), ft_arraylen(cub3d->map));
		mini_map_img->img_addr = mlx_get_data_addr(mini_map_img->img_ptr, &(mini_map_img->bpp), &(mini_map_img->size), &(mini_map_img->endian));
	}
	i = 0;
	while (i < ft_arraylen(cub3d->map))
	{
		j = 0;
		while (j < (int)ft_strlen((cub3d->map)[i]))
		{
			printf("w: %d, h: %d, char: %c\n",i, j, cub3d->map[i][j]);
			if (cub3d->map[i][j] == '1')
			{
				/*c
				*(int *)(mini_map_img->img_addr + i + j) = color;
				*/
				pixel = mini_map_img->img_addr + (i * mini_map_img->size) + (j * mini_map_img->bpp / 8);
				ft_memcpy(pixel ,&color, sizeof(unsigned int));
				printf("pixel color: %d\n", *pixel);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, mini_map_img, 100, 100);
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

	ft_print_minimap(cub3d);

	mlx_key_hook(cub3d->win_ptr, &ft_key_event, cub3d);
	mlx_hook(cub3d->win_ptr, 17, 1l << 0, &ft_close, cub3d);
	mlx_loop(cub3d->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	int		ret;
	t_cub3d	*cub3d;

	printf("cos: %f\n", 1 * cos(-3) - 0 * sin(-3));
	printf("cos: %f\n", 1 * cos(-6) - 0 * sin(-6));
	printf("cos: %f\n", 1 * cos(-9) - 0 * sin(-9));
	printf("cos: %f\n", 1 * cos(-12) - 0 * sin(-12));
	ret = 0;
	if (ac != 2)
		return (ERR_ARGS);
	ret = ft_parser(av[1], &cub3d);
	if (ret != 0)
		return (ft_return(ret, cub3d));

	ft_print_struct(cub3d);
	ft_run_cub3d(cub3d);
	return (ft_return(ret, cub3d));
}
