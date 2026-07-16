/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:15:47 by makui             #+#    #+#             */
/*   Updated: 2026/07/16 14:17:46 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_position_game(t_game *game, double *move_x, double *move_y)
{
	if (game->key_w)
	{
		*move_x += game->dir_x;
		*move_y += game->dir_y;
	}
	if (game->key_s)
	{
		*move_x -= game->dir_x;
		*move_y -= game->dir_y;
	}
	if (game->key_d)
	{
		*move_x -= game->dir_y;
		*move_y += game->dir_x;
	}
	if (game->key_a)
	{
		*move_x += game->dir_y;
		*move_y -= game->dir_x;
	}
}

void	update_player_position(t_game *game)
{
	double	move_x;
	double	move_y;
	double	rot_speed;
	double	len;

	move_x = 0;
	move_y = 0;
	rot_speed = 0.04;
	if (game->key_right)
		rotate_player(game, rot_speed);
	if (game->key_left)
		rotate_player(game, -rot_speed);
	update_position_game(game, &move_x, &move_y);
	if (move_x != 0 || move_y != 0)
	{
		len = sqrt(move_x * move_x + move_y * move_y);
		move_x /= len;
		move_y /= len;
		move_player(game, move_x, move_y);
	}
}
