/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:21:03 by makui             #+#    #+#             */
/*   Updated: 2026/07/09 09:22:35 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_wall_limits(t_ray *ray, int *start, int *end, int *line_h)
{
	double	perp_dist;

	if (ray->side == 0)
		perp_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		perp_dist = ray->side_dist_y - ray->delta_dist_y;
	if (perp_dist <= 0)
		perp_dist = 0.01;
	*line_h = (int)(SCREEN_HEIGHT / perp_dist);
	if (*line_h < 1)
		*line_h = 1;
	*start = -(*line_h) / 2 + SCREEN_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_h / 2 + SCREEN_HEIGHT / 2;
	if (*end >= SCREEN_HEIGHT)
		*end = SCREEN_HEIGHT - 1;
}

void	draw_wall_column(int x, t_game *game, t_ray *ray)
{
	int		line_h;
	int		start;
	int		end;
	int		y;
	double	wall_x;

	calc_wall_limits(ray, &start, &end, &line_h);
	wall_x = game->player_y + (ray->side_dist_x - ray->delta_dist_x) * ray->ray_dir_y;
	if (ray->side == 1)
		wall_x = game->player_x + (ray->side_dist_y - ray->delta_dist_y) * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < start)
			my_mlx_pixel_put(&game->img, x, y, rgb_to_int(game->color_ceil));
		else if (y > end)
			my_mlx_pixel_put(&game->img, x, y, rgb_to_int(game->color_floor));
		else
			my_mlx_pixel_put(&game->img, x, y, get_wall_pixel(game, ray,
					((y * 256 - SCREEN_HEIGHT * 128 + line_h * 128) * 64)
					/ line_h / 256, wall_x));
	}
}
