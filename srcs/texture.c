#include "cub3d.h"

int init_texture(t_cub3d *cub)
{
    if (access(cub->info->no, F_OK) != 0)
    {
       printf("no no!\n");
       return (1);
    }
    else
        printf("can read!\n");
    cub->images = malloc(sizeof(t_images));
    cub->images->no.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->no, &cub->images->no.w, &cub->images->no.h);
    cub->images->so.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->so, &cub->images->so.w, &cub->images->so.h);
    cub->images->we.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->we, &cub->images->we.w, &cub->images->we.h);
    cub->images->ea.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->info->ea, &cub->images->ea.w, &cub->images->ea.h);
    cub->images->no.img_addr = mlx_get_data_addr(cub->images->no.img_ptr, 
		&cub->images->no.bpp, &cub->images->no.size, &cub->images->no.endian);
    cub->images->so.img_addr = mlx_get_data_addr(cub->images->so.img_ptr, 
		&cub->images->so.bpp, &cub->images->so.size, &cub->images->so.endian);
    cub->images->we.img_addr = mlx_get_data_addr(cub->images->we.img_ptr, 
		&cub->images->we.bpp, &cub->images->we.size, &cub->images->we.endian);
    cub->images->ea.img_addr = mlx_get_data_addr(cub->images->ea.img_ptr, 
		&cub->images->ea.bpp, &cub->images->ea.size, &cub->images->ea.endian);
    printf("size:%d, %d, %d,%d\n",cub->images->no.size, cub->images->so.size, cub->images->we.size, cub->images->ea.size );
    printf("addr:%s, %s, %s, %s\n",cub->images->no.img_addr, cub->images->so.img_addr, cub->images->we.img_addr, cub->images->ea.img_addr );
    printf("pointer:%d, %d, %d, %d\n",(int)cub->images->no.img_ptr, (int)cub->images->so.img_ptr, (int)cub->images->we.img_ptr, (int)cub->images->ea.img_ptr );
    return (0);
}