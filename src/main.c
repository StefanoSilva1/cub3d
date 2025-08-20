#include "cub3d.h"

int	main(int c, char **v)
{
	t_cub	cub;

	if (c == 2 && !ft_strncmp(v[1], "init", 4))
	{
		ft_bzero(&cub, sizeof(t_cub));
		cub.map = create_hard_map();
		//adicionar em outra funcao posteriormente, isso mexe com inicializacao
		cub.sprite.ceilling_color = create_rgb(0, 135, 206, 235);
		cub.sprite.floor_color = create_rgb(0, 128, 200, 128);
		//---------------------------------------------------//
		cub_init(&cub);
		mlx_loop_hook(cub.mlx_connection, render, &cub); //chama a funcao e fica re-desenhando as iteracoes
		mlx_loop(cub.mlx_connection); //inicia a renderizacao
	}
	else
	{
		printf("pode nn man! :(\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
