#include "cub3d.h"

int	close_handler(t_cub *cub)
{	
	mlx_destroy_image(cub->mlx_connection, cub->img.img_ptr);
	mlx_destroy_window(cub->mlx_connection, cub->mlx_window);
	mlx_destroy_display(cub->mlx_connection);
	free(cub->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		close_handler(cub);
	return (0);
}
