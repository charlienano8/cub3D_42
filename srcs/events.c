/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:22:32 by makui             #+#    #+#             */
/*   Updated: 2026/06/17 15:04:19 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_game *game)
{
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free(game->map);
	printf("Game closed\n");
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	t_game	*game;

	double	move_speed;
	double	player_safety_radius;

	double	next_x;
	double	next_y;
	double	check_x;
	double	check_y;

	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	game = (t_game *)param;
	if (keycode == 65307)
		close_game(game);
	player_safety_radius = ((double)((TILE_SIZE / 3) / 2) / TILE_SIZE) + 0.01;
	move_speed = 0.1;
	if (keycode == 119)
	{
		next_x = game->player_x + game->dir_x * move_speed;
		next_y = game->player_y + game->dir_y * move_speed;
		if (next_x >= game->player_x)
			check_x = next_x + player_safety_radius;
		else
			check_x = next_x - player_safety_radius;
		if (game->map[(int)game->player_y][(int)check_x] != '1')
			game->player_x = next_x;
		if (next_y >= game->player_y)
			check_y = next_y + player_safety_radius;
		else
			check_y = next_y - player_safety_radius;
		if (game->map[(int)check_y][(int)game->player_x] != '1')
			game->player_y = next_y;
	}
	if (keycode == 115)
	{
		next_x = game->player_x - game->dir_x * move_speed;
		next_y = game->player_y - game->dir_y * move_speed;
		if (next_x >= game->player_x)
			check_x = next_x + player_safety_radius;
		else
			check_x = next_x - player_safety_radius;
		if (game->map[(int)game->player_y][(int)check_x] != '1')
			game->player_x = next_x;
		if (next_y >= game->player_y)
			check_y = next_y + player_safety_radius;
		else
			check_y = next_y - player_safety_radius;
		if (game->map[(int)check_y][(int)game->player_x] != '1')
			game->player_y = next_y;
	}
	if (keycode == 97)
	{
		next_x = game->player_x + game->dir_y * move_speed;
		next_y = game->player_y - game->dir_x * move_speed;
		if (next_x >= game->player_x)
			check_x = next_x + player_safety_radius;
		else
			check_x = next_x - player_safety_radius;
		if (game->map[(int)game->player_y][(int)check_x] != '1')
			game->player_x = next_x;
		if (next_y >= game->player_y)
			check_y = next_y + player_safety_radius;
		else
			check_y = next_y - player_safety_radius;
		if (game->map[(int)check_y][(int)game->player_x] != '1')
			game->player_y = next_y;
	}
	if (keycode == 100)
	{
		next_x = game->player_x - game->dir_y * move_speed;
		next_y = game->player_y + game->dir_x * move_speed;
		if (next_x >= game->player_x)
			check_x = next_x + player_safety_radius;
		else
			check_x = next_x - player_safety_radius;
		if (game->map[(int)game->player_y][(int)check_x] != '1')
			game->player_x = next_x;
		if (next_y >= game->player_y)
			check_y = next_y + player_safety_radius;
		else
			check_y = next_y - player_safety_radius;
		if (game->map[(int)check_y][(int)game->player_x] != '1')
			game->player_y = next_y;
	}
	rot_speed = 0.05;
	if (keycode == 65363)
	{
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
		game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
		game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
	}
	if (keycode == 65361)
	{
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(-rot_speed) - game->dir_y * sin(-rot_speed);
		game->dir_y = old_dir_x * sin(-rot_speed) + game->dir_y * cos(-rot_speed);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
		game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
	}
	return (0);
}
