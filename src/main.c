#include "cub3d.h"

int	main(int c, char **v)
{
	t_cub	cub;

	if (c == 2 && !ft_strncmp(v[1], "test", 4))
	{
		//cub.map = create_hard_map();
		cub_init(&cub);
		//mlx_put_image_to_window(cub.mlx_connection, cub.mlx_window, cub.img.img_ptr, 0, 0); //exibe a imagem na tela
		mlx_loop(cub.mlx_connection); //inicia a renderizacao
	}
	else
	{
		printf("pode nn man! :(\n");
		exit(EXIT_FAILURE);
	}
	//free_hard_map(cub.map);
	return (0);
}
