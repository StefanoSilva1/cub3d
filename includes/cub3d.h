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
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	t_pen_pos	position;
	char		**map;
}				t_cub;

typedef struct s_pen_pos
{
	int	x;
	int	y;
}				t_pen_pos;

void	cub_init(t_cub *cub);
int		close_handler(t_cub *cub);
int		key_handler(int keysym, t_cub *cub);
#endif