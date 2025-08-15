#include "cub3d.h"

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

/*int	mk_tree(t_cub *cub)
{
	cub->axys.y = HEIGHT / 2.5;
	while (cub->axys.y < HEIGHT / 3)
	{

	}
}*/

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
	mlx_put_image_to_window(cub->mlx_connection, cub->mlx_window, cub->img.img_ptr, 0, 0);
	return (0);
}
