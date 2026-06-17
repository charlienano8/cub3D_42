/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:44:11 by makui             #+#    #+#             */
/*   Updated: 2026/06/17 15:04:21 by makui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// For malloc, free and exit
# include <stdlib.h>

// For write and close
# include <unistd.h>

// For printf and perror
# include <stdio.h>

// For minilibx functions
# include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	t_img	img;
}	t_game;

int		close_game(t_game *game);
int		handle_keypress(int keycode, void *param);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_square(t_game *game, int x_start, int y_start, int size, int color);
int		render_next_frame(t_game *game);

#endif
