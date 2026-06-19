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

	game = (t_game *)param;
	move_speed = 0.1;
	player_safety_radius = ((double)((TILE_SIZE / 3) / 2) / TILE_SIZE) + 0.01;
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
	{
		if (game->map[(int)(game->player_y - move_speed - player_safety_radius)][(int)game->player_x] != '1' &&
			game->map[(int)(game->player_y - move_speed - player_safety_radius)][(int)(game->player_x + player_safety_radius)] != '1' &&
			game->map[(int)(game->player_y - move_speed - player_safety_radius)][(int)(game->player_x - player_safety_radius)] != '1')
			game->player_y -= move_speed;
	}
	if (keycode == 115)
	{
		if (game->map[(int)(game->player_y + move_speed + player_safety_radius)][(int)game->player_x] != '1' &&
			game->map[(int)(game->player_y + move_speed + player_safety_radius)][(int)(game->player_x + player_safety_radius)] != '1' &&
			game->map[(int)(game->player_y + move_speed + player_safety_radius)][(int)(game->player_x - player_safety_radius)] != '1')
			game->player_y += move_speed;
	}
	if (keycode == 97)
	{
		if (game->map[(int)game->player_y][(int)(game->player_x - move_speed - player_safety_radius)] != '1' &&
			game->map[(int)(game->player_y + player_safety_radius)][(int)(game->player_x - move_speed - player_safety_radius)] != '1' &&
			game->map[(int)(game->player_y - player_safety_radius)][(int)(game->player_x - move_speed - player_safety_radius)] != '1')
			game->player_x -= move_speed;
	}
	if (keycode == 100)
	{
		if (game->map[(int)game->player_y][(int)(game->player_x + move_speed + player_safety_radius)] != '1' &&
			game->map[(int)(game->player_y + player_safety_radius)][(int)(game->player_x + move_speed + player_safety_radius)] != '1' &&
			game->map[(int)(game->player_y - player_safety_radius)][(int)(game->player_x + move_speed + player_safety_radius)] != '1')
			game->player_x += move_speed;
	}
	return (0);
}
