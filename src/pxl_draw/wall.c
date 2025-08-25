#include "cub3d.h"

static t_wall	calculate_wall_dimension(t_ray *ray_result)
{
	t_wall	wall;

	if (ray_result->side == 0)
		wall.wall_dist = (ray_result->side_dst_x - ray_result->delta_dst_x);
	else
		wall.wall_dist = (ray_result->side_dst_y - ray_result->delta_dst_y);
	wall.height = (int)(HEIGHT / wall.wall_dist);
	wall.draw_start = -wall.height / 2 + HEIGHT / 2;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.draw_end = wall.height / 2 + HEIGHT / 2;
	if (wall.draw_end >= HEIGHT)
		wall.draw_end = HEIGHT - 1;
	return (wall);
}


