/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:31:01 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 15:42:19 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (argc == 2 && !ft_strncmp(argv[1], "init", 4))
	{
		cub.map = create_hard_map();
		//adicionar em outra funcao posteriormente, isso mexe com inicializacao
		cub.sprite.ceilling_color = create_rgb(0, 135, 206, 235);
		cub.sprite.floor_color = create_rgb(0, 128, 200, 128);
		//---------------------------------------------------//
		cub_init(&cub);
		mlx_loop_hook(cub.mlx_connection, render, &cub); //chama a funcao e fica re-desenhando as iteracoes
		mlx_loop(cub.mlx_connection); //inicia a renderizacao
	}
	else if (argc != 2 || !valid_format(argv[1]))
		error_handler(&cub, "Error: Invalid arguments\nUsage: ./cub3D maps/*.cub\n");
	if (argc == 2 && valid_format(argv[1]))
		close_handler(&cub);
	else
		error_handler(&cub, "Error: Invalid arguments\nUsage: ./cub3D maps/map.cub\n");
	return (0);
}
