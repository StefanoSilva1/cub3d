#include "cub3d.h"

int	main(int c, char **v)
{
	t_cub	cub;

	if (c == 2 && !ft_strncmp(v[1], "test", 4))
	{
		cub_init(&cub);
		mlx_put_image_to_window(cub.mlx_connection, cub.mlx_window, cub.img.img_ptr, 0, 0);
		mlx_loop(cub.mlx_connection);
	}
	else
	{
		printf("pode nn man! :(\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
