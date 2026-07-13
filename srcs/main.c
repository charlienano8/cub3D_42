/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_antoine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:04:49 by makui             #+#    #+#             */
/*   Updated: 2026/07/09 08:23:34 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->tex_no.img_ptr = mlx_xpm_file_to_image(game->mlx, game->texture_path_no, &w, &h);
	game->tex_so.img_ptr = mlx_xpm_file_to_image(game->mlx, game->texture_path_so, &w, &h);
	game->tex_we.img_ptr = mlx_xpm_file_to_image(game->mlx, game->texture_path_we, &w, &h);
	game->tex_ea.img_ptr = mlx_xpm_file_to_image(game->mlx, game->texture_path_ea, &w, &h);
	if (!game->tex_no.img_ptr || !game->tex_so.img_ptr || !game->tex_we.img_ptr
		|| !game->tex_ea.img_ptr)
		return (0);
	game->tex_no.addr = mlx_get_data_addr(game->tex_no.img_ptr, &game->tex_no.bits_per_pixel, &game->tex_no.line_length, &game->tex_no.endian);
	game->tex_so.addr = mlx_get_data_addr(game->tex_so.img_ptr, &game->tex_so.bits_per_pixel, &game->tex_so.line_length, &game->tex_so.endian);
	game->tex_we.addr = mlx_get_data_addr(game->tex_we.img_ptr, &game->tex_we.bits_per_pixel, &game->tex_we.line_length, &game->tex_we.endian);
	game->tex_ea.addr = mlx_get_data_addr(game->tex_ea.img_ptr, &game->tex_ea.bits_per_pixel, &game->tex_ea.line_length, &game->tex_ea.endian);
	return (1);
}

static void	init_keycode(t_game *game)
{
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_right = 0;
	game->key_left = 0;
}

int	main(int ac, char **av)
{
	t_game	game;
	int		ret;

	if (ac != 2)
		return (msg(ERR_AV));
	ret = parsing(&game, av);
	if (ret != 0)
		return (1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (msg(ERR_MLX));
	game.win = mlx_new_window(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3D by aborda and makui");
	if (!game.win)
		return (msg(ERR_MLX));
	game.img.img_ptr = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game.img.img_ptr)
		return (msg(ERR_MLX));
	game.img.addr = mlx_get_data_addr(game.img.img_ptr,
			&game.img.bits_per_pixel, &game.img.line_length,
			&game.img.endian);
	if (!init_textures(&game))
		return (msg(ERR_XPM_TEXTURES));
	init_keycode(&game);
	mlx_hook(game.win, 17, 0, (int (*)())(void *)close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, (int (*)())(void *)handle_keypress, &game);
	mlx_hook(game.win, 3, 1L << 1, (int (*)())(void *)handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, (int (*)())(void *)render_next_frame, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
