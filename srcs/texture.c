#include "cub3d.h"

int init_texture(t_cub3d *cub)
{
    int x;
    int y;
    //void *p;
    printf("OK!00000\n");
    //printf("cub->images->no_texture:%p\n", cub->images->no_texture.img_ptr);
    printf("ad:%s\n",cub->info->no);
    cub->images->no_texture.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->no, &x, &y);
    printf("OK!1111\n");
    // cub->images->so_texture = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->so, &cub->images->so_texture->x, &cub->images->so_texture->y);
    // cub->images->we_texture = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->we, &cub->images->we_texture->x, &cub->images->we_texture->y);
    // cub->images->ea_texture = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->ea, &cub->images->ea_texture->x, &cub->images->ea_texture->y);
    // cub->images->no_texture->img_addr = mlx_get_data_addr(cub->images->no_texture, 
	// 	&cub->images->no_texture->bpp, &cub->images->no_texture->size, &cub->images->no_texture->endian);
    // cub->images->so_texture->img_addr = mlx_get_data_addr(cub->images->so_texture, 
	// 	&cub->images->so_texture->bpp, &cub->images->so_texture->size, &cub->images->so_texture->endian);
    // cub->images->we_texture->img_addr = mlx_get_data_addr(cub->images->we_texture, 
	// 	&cub->images->we_texture->bpp, &cub->images->we_texture->size, &cub->images->we_texture->endian);
    // cub->images->ea_texture->img_addr = mlx_get_data_addr(cub->images->ea_texture, 
	// 	&cub->images->ea_texture->bpp, &cub->images->ea_texture->size, &cub->images->ea_texture->endian);
    printf("OK!\n");
    return (0);
}