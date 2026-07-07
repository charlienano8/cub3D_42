/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:19:29 by makui             #+#    #+#             */
/*   Updated: 2026/07/01 15:20:34 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycasting(int x, t_game *game, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = game->dir_x + game->plane_x * camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * camera_x;
	ray->map_x = (int)game->player_x;
	ray->map_y = (int)game->player_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	calculate_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player_y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	draw_wall_column(int x, t_game *game, t_ray *ray)
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		y;

	if (ray->side == 0)
		perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (perp_wall_dist <= 0)
		perp_wall_dist = 0.01;
	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 1)
		color = 0x555555;
	else
		color = 0x999999;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < draw_start)
			my_mlx_pixel_put(&(game->img), x, y, 0x3333CC);
		else if (y >= draw_start && y <= draw_end)
			my_mlx_pixel_put(&(game->img), x, y, color);
		else
			my_mlx_pixel_put(&(game->img), x, y, 0x666666);
		y++;
	}
}

int	raycasting_loop(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_raycasting(x, game, &ray);
		calculate_side_dist(game, &ray);
		perform_dda(game, &ray);
		draw_wall_column(x, game, &ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}
