#include "cub3d.h"
//#define PI 3.14159265359

int clean_screen(t_cub3d *cub3d)
{
	t_img	*dark_img;
	int i;
	int j;

	dark_img = ft_create_tile(cub3d, 0x00000000, 10);
	i = 0;
	while (i < ft_arraylen(cub3d->map))
	{
		j = 0;
		while (j < (int)ft_strlen((cub3d->map)[i]))
		{

			mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, dark_img->img_ptr, j * 10 + 20, i * 10 + 20 );
			j++;
		}
		i++;
	}
	return (0);
}
int	ft_move_player(int key, t_cub3d *cub3d)
{
	float	player_to_x;
	float	player_to_y;


	if (key == XK_w)
	{
		printf("player x: %f, y: %f\n", cub3d->player->pos_x, cub3d->player->pos_y);
		player_to_x = cub3d->player->pos_x + cub3d->player->dir_x * MOVE_DIST;
		player_to_y = cub3d->player->pos_y + cub3d->player->dir_y * MOVE_DIST;
		if (cub3d->map[(int)player_to_x][(int)player_to_y] != '1')
		{
			cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y] = '0';
			printf("player to x: %f, y: %f\n", player_to_x, player_to_y);
			cub3d->player->pos_x = player_to_x;
			cub3d->player->pos_y = player_to_y;
			cub3d->map[(int)player_to_x][(int)player_to_y] = 'W';
		}
		clean_screen(cub3d);
	}
	if (key == XK_s)
	{
		player_to_x = cub3d->player->pos_x - cub3d->player->dir_x * MOVE_DIST;
		player_to_y = cub3d->player->pos_y - cub3d->player->dir_y * MOVE_DIST;
		if (cub3d->map[(int)player_to_x][(int)player_to_y] != '1')
		{
			cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y] = '0';
			printf("player x: %f, y: %f\n", cub3d->player->pos_x, cub3d->player->pos_y);
			printf("player to x: %f, y: %f\n", player_to_x, player_to_y);
			cub3d->player->pos_x = player_to_x;
			cub3d->player->pos_y = player_to_y;
			cub3d->map[(int)player_to_x][(int)player_to_y] = 'W';
		}
		clean_screen(cub3d);
	}
	if (key == XK_a)
	{
		player_to_x = cub3d->player->pos_x - cub3d->player->dir_y * MOVE_DIST;
		player_to_y = cub3d->player->pos_y + cub3d->player->dir_x * MOVE_DIST;
		if (cub3d->map[(int)player_to_x][(int)player_to_y] != '1')
		{
			cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y] = '0';
			printf("player x: %f, y: %f\n", cub3d->player->pos_x, cub3d->player->pos_y);
			printf("player to x: %f, y: %f\n", player_to_x, player_to_y);
			cub3d->player->pos_x = player_to_x;
			cub3d->player->pos_y = player_to_y;
			cub3d->map[(int)player_to_x][(int)player_to_y] = 'W';
			clean_screen(cub3d);
		}
	}
	if (key == XK_d)
	{
		player_to_x = cub3d->player->pos_x + cub3d->player->dir_y * MOVE_DIST;
		player_to_y = cub3d->player->pos_y - cub3d->player->dir_x * MOVE_DIST;
		if (cub3d->map[(int)player_to_x][(int)player_to_y] != '1')
		{
			cub3d->map[(int)cub3d->player->pos_x][(int)cub3d->player->pos_y] = '0';
			printf("player x: %f, y: %f\n", cub3d->player->pos_x, cub3d->player->pos_y);
			printf("player to x: %f, y: %f\n", player_to_x, player_to_y);
			cub3d->player->pos_x = player_to_x;
			cub3d->player->pos_y = player_to_y;
			cub3d->map[(int)player_to_x][(int)player_to_y] = 'W';
			clean_screen(cub3d);
		}
	}
	ft_print_canvas(cub3d);
	ft_print_minimap(cub3d);
	return (0);
}


int	ft_rotate_player(t_cub3d *cub3d, int key)
{
	if (key == XK_Left)
	{
		cub3d->player->angle+=0.1;
		if (cub3d->player->angle > 2 * PI)
			cub3d->player->angle-= 2 * PI;
		// cub3d->player->dir_x = cos(cub3d->player->angle) * cub3d->player->pos_x;
		// cub3d->player->dir_y = sin(cub3d->player->angle) * cub3d->player->pos_y;
		cub3d->player->dir_x = cos(cub3d->player->angle);
		cub3d->player->dir_y = sin(cub3d->player->angle);
		printf("here1, x=%f, y=%f\n",cub3d->player->dir_x,  cub3d->player->dir_y);
	}
	if (key == XK_Right)
	{
		cub3d->player->angle-=0.1;
		if (cub3d->player->angle < 0)
			cub3d->player->angle+= 2 * PI;
		cub3d->player->dir_x = cos(cub3d->player->angle);
		cub3d->player->dir_y = sin(cub3d->player->angle);
		// cub3d->player->dir_x = cos(cub3d->player->angle) * cub3d->player->pos_x;
		// cub3d->player->dir_y = sin(cub3d->player->angle) * cub3d->player->pos_y;
		printf("here2, x=%f, y=%f\n",cub3d->player->dir_x,  cub3d->player->dir_y);
	}
	clean_screen(cub3d);
	ft_print_canvas(cub3d);
	ft_print_minimap(cub3d);
	return (0);
}


int	ft_key_event(int key, t_cub3d *cub3d)
{
	
	(void)cub3d;
	if (key == XK_Escape)
		ft_close(cub3d);
	if (key == XK_a || key == XK_d || key == XK_w || key == XK_s)
		ft_move_player(key, cub3d);
	if (key == XK_Left || key == XK_Right)
	{
		ft_rotate_player(cub3d, key);
		// ft_putstr_fd("rotate: ", 1);
		// ft_putnbr_fd(key, 1);
	}
	return (0);
}
