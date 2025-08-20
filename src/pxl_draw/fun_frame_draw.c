#include "cub3d.h"

#define COLOR_BROWN 0x654321
#define COLOR_GREEN 0x008000

void	put_pxl_in_img(t_img *img, t_cub *cub, int color)
{
	int		y;
	int		x;
	char	*pxl_address;

	y = cub->axys.y;
	x = cub->axys.x;
	pxl_address = img->pxl_ptr + (y * img->l_len + x * (img->bits_per_pxl /8));
	*(unsigned int *)pxl_address = color;
}

void   mk_tree(t_cub *cub)
{
    int tree_start_x = WIDTH * 0.8; 
    int tree_end_x = WIDTH * 0.95;
    int leaves_start_y = HEIGHT * 0.3;
    int leaves_end_y = HEIGHT * 0.6;
    int trunk_start_y = leaves_end_y;
    int trunk_end_y = HEIGHT * 0.9;
    int trunk_width = (tree_end_x - tree_start_x) / 3;
    int trunk_start_x = tree_start_x + trunk_width;
    int trunk_end_x = trunk_start_x + trunk_width;

    cub->axys.y = leaves_start_y;
    while (cub->axys.y < leaves_end_y)
    {
        cub->axys.x = tree_start_x;
        while (cub->axys.x < tree_end_x)
        {
            put_pxl_in_img(&cub->img, cub, COLOR_GREEN);
            cub->axys.x++;
        }
        cub->axys.y++;
    }
    cub->axys.y = trunk_start_y;
    while (cub->axys.y < trunk_end_y)
    {
        cub->axys.x = trunk_start_x;
        while (cub->axys.x < trunk_end_x)
        {
            put_pxl_in_img(&cub->img, cub, COLOR_BROWN);
            cub->axys.x++;
        }
        cub->axys.y++;
    }
}

int	render(t_cub *cub)
{
	cub->axys.y = 0;
	while (cub->axys.y < HEIGHT / 2)
	{
		cub->axys.x = 0;
		while (cub->axys.x < WIDTH)
		{
			put_pxl_in_img(&cub->img, cub, 0x87CEEB);
			cub->axys.x++;
		}
		cub->axys.y++;
	}
	cub->axys.y = HEIGHT / 2;
	while (cub->axys.y < HEIGHT)
	{
		cub->axys.x = 0;
		while (cub->axys.x < WIDTH)
		{
			put_pxl_in_img(&cub->img, cub, 0x964B00);
			cub->axys.x++;
		}
		cub->axys.y++;
	}
	mk_tree(cub);
	mlx_put_image_to_window(cub->mlx_connection, cub->mlx_window, cub->img.img_ptr, 0, 0);
	return (0);
}

//mlx_loop_hook(cub.mlx_connection, render, &cub);
