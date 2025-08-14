#include "cub3d.h"

static void	err_exit(t_cub *cub)
{
	ft_putstr_fd("ERROR: filed to init MLX", STDERR_FILENO);
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->img.img_ptr);
	if (cub->mlx_window)
		mlx_destroy_window(cub->mlx_connection, cub->mlx_window);
	if (cub->mlx_connection)
	{
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
	}
	exit(EXIT_FAILURE);
}
