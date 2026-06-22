/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:57:24 by makui             #+#    #+#             */
/*   Updated: 2026/06/17 15:04:24 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 640 || y < 0 || y >= 480)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_game *game, int x_start, int y_start, int size, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(&game->img, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_game *game)
{
	int	x;
	int	y;
	int	player_size;

	int	i;
	double	line_x;
	double	line_y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_square(game, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0xFFFFFF);
			else if (game->map[y][x] == '0')
				draw_square(game, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, 0x222222);
			x++;
		}
		y++;
	}
	player_size = TILE_SIZE / 3;
	draw_square(game, game->player_x * TILE_SIZE - (player_size / 2), game->player_y * TILE_SIZE - (player_size / 2), player_size, 0xFF0000);
	i = 0;
	while (i < 15)
	{
		line_x = (game->player_x * TILE_SIZE) + (game->dir_x * i);
		line_y = (game->player_y * TILE_SIZE) + (game->dir_y * i);
		my_mlx_pixel_put(&game->img, (int)line_x, (int)line_y, 0x00FF00);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}
