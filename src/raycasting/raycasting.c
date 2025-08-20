#include "cub3d.h"

void	raycasting(t_cub *cub, int x)
{
	double	camera_x;
	double	ray_dir_y;
	double	ray_dir_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray_dir_x = cub->player.dir_x + cub->player.plane_x * camera_x;
	ray_dir_y = cub->player.dir_y + cub->player.plane_y * camera_x;
}