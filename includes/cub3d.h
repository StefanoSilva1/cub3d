/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:12:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 11:43:03 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Headers */
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# include "libft.h"

# define WIDTH 1000
# define HEIGHT 1000

/* Structs */
typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bits_per_pxl;
	int		endian;
	int		l_len;
}				t_img;

typedef struct s_cub
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_rgb;
	int		ceiling_rgb;
	char	**map;
	int		map_width;
	int		map_height;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_cub;	

void	cub_init(t_cub *cub);
int		close_handler(t_cub *cub);
int		key_handler(int keysym, t_cub *cub);
#endif