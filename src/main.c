#include "cub3d.h"

int	main(int c, char **v)
{
	t_cub	cub;

	if (c != 2 || ft_strncmp(v[1], "init", 4) != 0)
	{
		printf("pode nn man! :(\n");
		exit(EXIT_FAILURE);
	}
	init_data(&cub);
	cub_init(&cub);
	mlx_loop_hook(cub.mlx_connection, render, &cub); //chama a funcao e fica re-desenhando as iteracoes
	mlx_loop(cub.mlx_connection); //inicia a renderizacao
	return (0);
}
