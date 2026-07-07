/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:04:49 by makui             #+#    #+#             */
/*   Updated: 2026/06/21 15:52:07 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**generate_test_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 15);
	if (!map)
		return (NULL);
	map[0] = "        1111111111111111111111111";
	map[1] = "        1000000000110000000000001";
	map[2] = "        1011000001110000000000001";
	map[3] = "        1001000000000000000000001";
	map[4] = "111111111011000001110000000000001";
	map[5] = "100000000011000001110111111111111";
	map[6] = "11110111111111011100000010001";
	map[7] = "11110111111111011101010010001";
	map[8] = "11000000110101011100000010001";
	map[9] = "10000000000000001100000010001";
	map[10] = "10000000000000001101010010001";
	map[11] = "1100000111010101111101111000111";
	map[12] = "11110111 1110101 101111010001";
	map[13] = "11111111 1111111 111111111111";
	map[14] = NULL;
	return (map);
}

int	main(void)
{
	t_game	game;

	game.map = generate_test_map();
	game.player_x = 20.5;
	game.player_y = 3.5;
	game.dir_x = 0.0;
	game.dir_y = -1.0;
	game.plane_x = 0.66;
	game.plane_y = 0.0;
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
	mlx_hook(game.win, 17, 0, (int (*)())(void *)close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, (int (*)())(void *)handle_keypress, &game);
	mlx_loop_hook(game.mlx, (int (*)())(void *)render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
