/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:59:25 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 14:08:23 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
