/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:22:32 by makui             #+#    #+#             */
/*   Updated: 2026/06/09 11:25:54 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_game *game)
{
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

	game = (t_game *)param;
	if (keycode == 65307)
		close_game(game);
	return (0);
}
