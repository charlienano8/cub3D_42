/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:22:32 by makui             #+#    #+#             */
/*   Updated: 2026/07/09 08:42:12 by aborda           ###   ########.fr       */
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
		free_map(game->map);
	printf("Game closed\n");
	exit(0);
	return (0);
}

void	move_player(t_game *game, double dir_x, double dir_y)
{
	double	safety;
	double	next_x;
	double	next_y;
	double	check_x;
	double	check_y;

	safety = ((double)((TILE_SIZE / 3) / 2) / TILE_SIZE) + 0.01;
	next_x = game->player_x + dir_x * 0.1;
	next_y = game->player_y + dir_y * 0.1;
	check_x = next_x + safety;
	if (next_x < game->player_x)
		check_x = next_x - safety;
	if (game->map[(int)game->player_y][(int)check_x] != '1')
		game->player_x = next_x;
	check_y = next_y + safety;
	if (next_y < game->player_y)
		check_y = next_y - safety;
	if (game->map[(int)check_y][(int)game->player_x] != '1')
		game->player_y = next_y;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
	game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}

int	handle_keypress(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307)
		close_game(game);
	if (keycode == 119)
		game->key_w = 1;
	if (keycode == 115)
		game->key_s = 1;
	if (keycode == 97)
		game->key_a = 1;
	if (keycode == 100)
		game->key_d = 1;
	if (keycode == 65363)
		game->key_right = 1;
	if (keycode == 65361)
		game->key_left = 1;
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 119)
		game->key_w = 0;
	if (keycode == 115)
		game->key_s = 0;
	if (keycode == 97)
		game->key_a = 0;
	if (keycode == 100)
		game->key_d = 0;
	if (keycode == 65363)
		game->key_right = 0;
	if (keycode == 65361)
		game->key_left = 0;
	return (0);
}
