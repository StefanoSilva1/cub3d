/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:51:36 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 11:52:08 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_handler(t_cub *cub)
{	
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->img.img_ptr);
	if (cub->mlx_window)
		mlx_destroy_window(cub->mlx_connection, cub->mlx_window);
	if (cub->mlx_connection)
	{
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
	}
	exit(EXIT_SUCCESS);
}