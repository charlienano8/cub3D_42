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

	game = (t_game *)param;
	move_speed = 0.1;
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
		game->player_y -= move_speed;
	if (keycode == 115)
		game->player_y += move_speed;
	if (keycode == 97)
		game->player_x -= move_speed;
	if (keycode == 100)
		game->player_x += move_speed;
	return (0);
}
