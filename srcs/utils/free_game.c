/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:40:55 by aborda            #+#    #+#             */
/*   Updated: 2026/07/19 10:24:19 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	free(game->texture_path_no);
	free(game->texture_path_so);
	free(game->texture_path_we);
	free(game->texture_path_ea);
	free(game->map_line_len);
	free_map(game->map);
}

void	free_mlx(t_game *game)
{
	if (game->tex_no.img_ptr)
		mlx_destroy_image(game->mlx, game->tex_no.img_ptr);
	if (game->tex_so.img_ptr)
		mlx_destroy_image(game->mlx, game->tex_so.img_ptr);
	if (game->tex_we.img_ptr)
		mlx_destroy_image(game->mlx, game->tex_we.img_ptr);
	if (game->tex_ea.img_ptr)
		mlx_destroy_image(game->mlx, game->tex_ea.img_ptr);
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
