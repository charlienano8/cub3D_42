/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:04:49 by makui             #+#    #+#             */
/*   Updated: 2026/06/09 11:22:18 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**generate_test_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 6);
	if (!map)
		return (NULL);
	map[0] = "111111";
	map[1] = "100001";
	map[2] = "101001";
	map[3] = "100001";
	map[4] = "111111";
	map[5] = NULL;
	return (map);
}

int	main(void)
{
	t_game	game;

	game.map = generate_test_map();
	game.player_x = 2.5;
	game.player_y = 2.5;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, 640, 480, "cub3D by aborda and makui");
	if (!game.win)
		return (1);
	mlx_hook(game.win, 17, 0, (int (*)())(void *)close_game, &game);
	mlx_hook(game.win, 2, 1L<<0, (int (*)())(void *)handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
