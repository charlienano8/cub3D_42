/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cameras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:36:06 by aborda            #+#    #+#             */
/*   Updated: 2026/07/08 16:28:44 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_camera_n(t_game *game)
{
	game->dir_x = 0.0;
	game->dir_y = -1.0;
	game->plane_x = 0.66;
	game->plane_y = 0.0;
}

static void	init_camera_s(t_game *game)
{
	game->dir_x = 0.0;
	game->dir_y = 1.0;
	game->plane_x = -0.66;
	game->plane_y = 0.0;
}

static void	init_camera_e(t_game *game)
{
	game->dir_x = 1.0;
	game->dir_y = 0.0;
	game->plane_x = 0.0;
	game->plane_y = 0.66;
}

static void	init_camera_w(t_game *game)
{
	game->dir_x = -1.0;
	game->dir_y = 0.0;
	game->plane_x = 0.0;
	game->plane_y = -0.66;
}

void	init_cameras(t_game *game)
{
	if (game->player_dir == 'N')
		init_camera_n(game);
	if (game->player_dir == 'S')
		init_camera_s(game);
	if (game->player_dir == 'E')
		init_camera_e(game);
	if (game->player_dir == 'W')
		init_camera_w(game);
}
