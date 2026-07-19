/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:04:49 by makui             #+#    #+#             */
/*   Updated: 2026/07/19 10:27:46 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_keycode(t_game *game)
{
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_right = 0;
	game->key_left = 0;
}

int	init_mlx_and_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3D by aborda and makui");
	if (!game->win)
		return (0);
	game->img.img_ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img_ptr)
		return (0);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (msg(ERR_AV));
	if (0 != parsing(&game, av))
		return (1);
	if (!init_mlx_and_window(&game))
		return (free_mlx(&game), free_game(&game), msg(ERR_MLX));
	if (!init_textures(&game))
		return (free_mlx(&game), free_game(&game), msg(ERR_XPM_TEXTURES));
	init_keycode(&game);
	mlx_hook(game.win, 17, 0, (int (*)())(void *)close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, (int (*)())(void *)handle_keypress, &game);
	mlx_hook(game.win, 3, 1L << 1, (int (*)())(void *)handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, (int (*)())(void *)render_next_frame, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
