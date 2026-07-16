/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:51:20 by makui             #+#    #+#             */
/*   Updated: 2026/07/16 13:53:26 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_textures_data(t_game *game)
{
	game->tex_no.addr = mlx_get_data_addr(game->tex_no.img_ptr,
			&game->tex_no.bits_per_pixel, &game->tex_no.line_length,
			&game->tex_no.endian);
	game->tex_so.addr = mlx_get_data_addr(game->tex_so.img_ptr,
			&game->tex_so.bits_per_pixel, &game->tex_so.line_length,
			&game->tex_so.endian);
	game->tex_we.addr = mlx_get_data_addr(game->tex_we.img_ptr,
			&game->tex_we.bits_per_pixel, &game->tex_we.line_length,
			&game->tex_we.endian);
	game->tex_ea.addr = mlx_get_data_addr(game->tex_ea.img_ptr,
			&game->tex_ea.bits_per_pixel, &game->tex_ea.line_length,
			&game->tex_ea.endian);
}

int	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->tex_no.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->texture_path_no, &w, &h);
	game->tex_so.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->texture_path_so, &w, &h);
	game->tex_we.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->texture_path_we, &w, &h);
	game->tex_ea.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->texture_path_ea, &w, &h);
	if (!game->tex_no.img_ptr || !game->tex_so.img_ptr || !game->tex_we.img_ptr
		|| !game->tex_ea.img_ptr)
		return (0);
	get_textures_data(game);
	return (1);
}
