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

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(cub));
	if (argc != 2 || !valid_format(argv[1]))
		error_handler(&cub, "Error: Invalid arguments\nUsage: ./cub3D maps/map.cub\n");
	cub_init(&cub);
	mlx_put_image_to_window(cub.mlx_connection, cub.mlx_window, cub.img.img_ptr, 0, 0);
	mlx_loop(cub.mlx_connection);
	return (0);
}
