#include "cub3d.h"

int	ft_print_canvas(t_cub3d *cub3d)
{
	double		x;
	t_img	*canvas;
	t_player *player;

	player = cub3d->plr;

	canvas = malloc(sizeof(t_img));
	canvas->img_ptr = mlx_new_image(cub3d->mlx_ptr, 1024, 768);
	canvas->img_addr = mlx_get_data_addr(canvas->img_ptr, &(canvas->bpp), &(canvas->size), &(canvas->endian));

	x = 0.00;
	while (x <= 1024)
	{
		double camera_x = 2 * x / 1024 - 1;
		printf("camera_x: %f\n", camera_x);
		double ray_dir_x = player->d_x + player->pl_x * camera_x;
		double ray_dir_y = player->d_y + player->pl_y * camera_x;

		int	map_x = (int)(player->p_x);
		int	map_y = (int)(player->p_y);

		double side_dist_x;
		double side_dist_y;
		double delta_dist_x = 1000000;
		double delta_dist_y = 1000000;

		if (ray_dir_x != 0)
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y != 0)
			delta_dist_y = fabs(1 / ray_dir_y);


		int	step_x;
		int	step_y;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (player->p_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - player->p_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (player->p_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - player->p_y) * delta_dist_y;
		}

		int	hit = 0;
		int	side;

		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (cub3d->map[map_x][map_y] == '1')
				hit = 1;
		}

		double perp_wall_dist;

		if (side == 0)
			perp_wall_dist = side_dist_x - delta_dist_x;
		else
			perp_wall_dist = side_dist_y - delta_dist_y;

		printf("Ray_dir_x: %f, Ray_dir_y: %f", ray_dir_x, ray_dir_y);
		printf("mapx: %d, mapy: %d\n", map_x,map_y);
		printf("perp wall dist: %f\n", perp_wall_dist);

		int	y = 0;
		char *pixel;
		int color = 0x0000FF00;
		int	color_1 = 0x0000AA00;
		while (y <= 768)
		{
			if (y > 384 - (int)((768 / perp_wall_dist) / 2) && y < 384 + (int)((768 / perp_wall_dist) / 2))
			{
				pixel = canvas->img_addr + ((int)(y) * canvas->size) + (int)x * (canvas->bpp / 8);
				if (side == 0)
					ft_memcpy(pixel, &color, sizeof(unsigned int));
				else
					ft_memcpy(pixel, &color_1, sizeof(unsigned int));
			}
			y++;
		}

		x++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, canvas->img_ptr,0 ,0) ;
	return (0);
}
