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

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		map_width;
	int		map_height;
}				t_map;

typedef struct s_pen_pos
{
	int	x;
	int	y;
}				t_pen_pos;

typedef struct s_sprite_img
{
	int	floor_color;
	int	ceilling_color;
	int	wall_color;
}				t_sprite_img;

typedef struct s_cub
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_window;
	t_img			img;
	t_pen_pos		axys;
	t_sprite_img	sprite;
	char			**map;
}				t_cub;

void	cub_init(t_cub *cub);
int		close_handler(t_cub *cub);
int		error_handler(t_cub *cub, char *error_message);
void	cleanup(t_cub *cub);
int		key_handler(int keysym, t_cub *cub);

void	put_pxl_in_img(t_img *img, int x, int y, int color);
//int		render_frame_tree(t_cub *cub);

char	**create_hard_map(void);
void	free_hard_map(char **map);

int		create_rgb(int t, int r, int g, int b);
void	draw_background(t_cub *cub);
int		render(t_cub *cub);
void	free_map(char **map);
int		valid_format(char *str);

#endif