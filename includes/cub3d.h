/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:12:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/29 11:27:55 by sdavi-al         ###   ########.fr       */
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
#include <fcntl.h>
# include "../minilibx-linux/mlx.h"

# include "libft.h"
#include "get_next_line.h"

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
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
	int		x;
	int		y;
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

typedef struct s_wall
{
	double	wall_dist;
	int		height;
	int		draw_start;
	int		draw_end;
}				t_wall;

typedef struct s_player
{
	double	dir_y;
	double	dir_x;
	double	cam_plane_y;
	double	cam_plane_x;
	double	pos_y;
	double	pos_x;
}				t_player;

typedef struct s_ray
{
	bool	hit;
	int		side;
	int		map_y;
	int		map_x;
	int		step_y;
	int		step_x;
	double	delta_dst_y;
	double	delta_dst_x;
	double	side_dst_y;
	double	side_dst_x;
}				t_ray;

typedef struct s_line
{
	char			*current;
	struct s_line	*next;
}				t_line;

typedef struct s_cub
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_window;
	t_map			map_set;
	t_img			img;
	t_pen_pos		axys;
	t_sprite_img	sprite;
	t_player		player;
	char			**map;
	t_img			north_texture;
	t_img			south_texture;
	t_img			west_texture;
	t_img			east_texture;
}				t_cub;

/*typedef struct s_cube
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_rgb;
	int		ceiling_rgb;
	char	**map;
	int		map_width;

	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_cube;*/

void	cub_init(t_cub *cub);
void	init_data(t_cub *cub);
int		close_handler(t_cub *cub);
int		error_handler(t_cub *cub, char *error_message);
void	cleanup(t_cub *cub);
int		key_handler(int keysym, t_cub *cub);

void	put_pxl_in_img(t_img *img, int x, int y, int color);

char	**create_hard_map(void);
//void	free_hard_map(char **map);

int		create_rgb(int t, int r, int g, int b);
void	draw_background(t_cub *cub);
int		render(t_cub *cub);
int		valid_format(char *str);

void	init_player(t_cub *cub);

void	raycasting(t_cub *cub, int x);

void	draw_wall(t_cub *cub, int horizontal_slice, t_ray *ray_result);
void	free_array(char **array);
int		valid_format(char *str);
char	*get_next_line(int fd);
void	parse_texture(char *line, t_cub *cub);
void	parse_color(char *line, t_cub *cub);
int		all_configs_set(t_cub *cub);
void	parse_map_grid(char *line, t_cub *cub, int fd);
int		has_only_valid_characters(char **map);
int		get_map_width(char **map);
void	player_coordinates(char **map, t_cub *cub);
char	**duplicate_map(char **map);
int		flood_fill(char **map_copy, t_cub *cub, int y, int x);
t_line	*new_node(char *line);
int		count_lines(t_line	*map_list);
void	free_list(t_line *head);
t_line	*add_node_back(t_line **list_head, t_line *new_node);
int		main_parser(char *filename, t_cub *cub);
int		is_map_closed(t_cub *cub);

#endif