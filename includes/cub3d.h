/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:44:11 by makui             #+#    #+#             */
/*   Updated: 2026/06/30 08:51:32 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Libraries */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

/* Project Headers */
# include "libft.h"
# include "messages.h"

/* Minilibx */
# include "mlx.h"

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define TILE_SIZE 16

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
	int		line_map_nb;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_img	img;
}	t_game;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
}	t_ray;

/* Parsing */
int		create_map(t_game *game);
int		fill_map(t_game *game, char *file);
int		is_valid_map_chars(t_game *game);

/* Game */
int		init_game(t_game *game, char *file);
int		close_game(t_game *game);
int		handle_keypress(int keycode, void *param);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_square(t_game *game, int x_start, int y_start, int size, int color);
int		render_next_frame(t_game *game);
int		raycasting_loop(t_game *game);

/* Utils */
int		is_cub_extension(char *str);
int		is_map_line(char *line);
int		line_map_count(char *file);

#endif
