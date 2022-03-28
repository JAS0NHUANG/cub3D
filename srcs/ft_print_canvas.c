#include "cub3d.h"
// void calcu_side_dist(t_cub3d *cub3d, t_ray *ray)
// {


// }
t_my_img *select_texture(t_cub3d *cub, t_ray ray)
{
	if (ray.side)
	{
		if (ray.dir_y > 0)
			return (&cub->images->no);
		if (ray.dir_y < 0)
			return (&cub->images->so);
	}
	else if (!ray.side) //x
	{	
		if (ray.dir_x > 0)
			return (&cub->images->ea);
		if (ray.dir_x < 0)
			return (&cub->images->we);
	}
	return (0);
}

int	ft_print_canvas(t_cub3d *cub3d)
{
	double		x;
	t_my_img	*canvas;
	t_player *player;
	t_ray	ray;
	t_my_img *texture;

	player = cub3d->plr;

	canvas = malloc(sizeof(t_my_img));
	canvas->img_ptr = mlx_new_image(cub3d->mlx_ptr, S_W, S_H);
	canvas->img_addr = mlx_get_data_addr(canvas->img_ptr, &(canvas->bpp), &(canvas->size), &(canvas->endian));

	x = 0.00;
	while (x <= S_W)
	{
		double camera_x = 2 * x / S_W - 1;
		ray.dir_x = player->d_x + player->pl_x * camera_x;
		ray.dir_y = player->d_y + player->pl_y * camera_x;


		// int	step_x;
		// int	step_y;
		int	map_x;
		int	map_y;
	
		map_x= (int)(cub3d->plr->p_x);
		map_y= (int)(cub3d->plr->p_y);
		ray.delta_dist_x = 1000000;
		ray.delta_dist_y = 1000000;
		if (ray.dir_x != 0)
			ray.delta_dist_x = fabs(1 / ray.dir_x);
		if (ray.dir_y != 0)
			ray.delta_dist_y = fabs(1 / ray.dir_y);
		if (ray.dir_x < 0)
		{
			ray.step_x = -1;
			ray.side_dist_x = (cub3d->plr->p_x - map_x) * ray.delta_dist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.side_dist_x = (map_x + 1.0 - cub3d->plr->p_x) * ray.delta_dist_x;
		}
		if (ray.dir_y < 0)
		{
			ray.step_y = -1;
			ray.side_dist_y = (cub3d->plr->p_y - map_y) * ray.delta_dist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.side_dist_y = (map_y + 1.0 - cub3d->plr->p_y) * ray.delta_dist_y;
		}

		int	hit = 0;
		// int	side;

		while (hit == 0)
		{
			if (ray.side_dist_x < ray.side_dist_y)
			{
				ray.side_dist_x += ray.delta_dist_x;
				map_x += ray.step_x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist_y += ray.delta_dist_y;
				map_y += ray.step_y;
				ray.side = 1;
			}
			if (cub3d->map[map_x][map_y] == '1')
				hit = 1;
		}

		//double perp_wall_dist;

		if (ray.side == 0)
			ray.perp_wall_dist = ray.side_dist_x - ray.delta_dist_x;
		else
			ray.perp_wall_dist = ray.side_dist_y - ray.delta_dist_y;

		printf("Ray_dir_x: %f, Ray_dir_y: %f", ray.dir_x, ray.dir_y);
		printf("mapx: %d, mapy: %d\n", map_x,map_y);
		printf("perp wall dist: %f\n", ray.perp_wall_dist);

		//Calculate height of line to draw on screen
      	int lineHeight = (int)(S_H / ray.perp_wall_dist);

      	//calculate lowest and highest pixel to fill in current stripe
      	int drawStart = -lineHeight / 2 + S_H / 2;
      	if(drawStart < 0) drawStart = 0;
      	int drawEnd = lineHeight / 2 + S_H / 2;
      	if(drawEnd >= S_H) drawEnd = S_H - 1;
		
		//double wallX; //where exactly the wall was hit
      	if (ray.side == 0)
			ray.wall_x = player->p_y + ray.perp_wall_dist * ray.dir_y;
      	else
		  	ray.wall_x = player->p_x + ray.perp_wall_dist * ray.dir_x;
      	ray.wall_x -= floor((ray.wall_x));

		printf("ray.wall_x :%f\n", ray.wall_x);
		texture = select_texture(cub3d, ray);	
		int texX = (int)(ray.wall_x * (double)(texture->w));
      	if(ray.side == 0 && ray.dir_x > 0) texX = texture->w - texX - 1;
      	if(ray.side == 1 && ray.dir_y < 0) texX = texture->w - texX - 1;

		//lineHeight = drawEnd - drawStart;
		double step = 1.0 * texture->h / lineHeight;
		double texPos = (drawStart - S_H / 2 + lineHeight / 2) * step;
		int y = drawStart;
		char *pixel;
		printf("here\n %d\n", texture->size);
		printf("cub:%d\n", cub3d->images->so.size);
		while (y < drawEnd && y < S_W)
      	{
        	int texY = (int)texPos & (texture->h - 1);
			printf("here1%p\n",texture->img_addr);
			int color = ((int *)texture->img_addr)[(texture->size / 4) * texY + texX];
			printf("here2\n");
			pixel = canvas->img_addr + ((int)(y) * canvas->size) + (int)x * (canvas->bpp / 8);
			*(unsigned int *)pixel = color;
        	texPos += step;
			y++;
     	}
		// int	y = 0;
		// char *pixel;
		// int color = 0x0000FF00;
		// int	color_1 = 0x0000AA00;
		// while (y <= S_H)
		// {
		// 	if (y > S_H/2 - (int)((S_H / ray.perp_wall_dist) / 2) && y < S_H/2 + (int)((S_H / ray.perp_wall_dist) / 2))
		// 	{
		// 		pixel = canvas->img_addr + ((int)(y) * canvas->size) + (int)x * (canvas->bpp / 8);
		// 		if (ray.side == 0)
		// 			ft_memcpy(pixel, &color, sizeof(unsigned int));
		// 		else
		// 			ft_memcpy(pixel, &color_1, sizeof(unsigned int));
		// 	}
		// 	y++;
		// }

		x++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, canvas->img_ptr,0 ,0) ;
	return (0);
}
