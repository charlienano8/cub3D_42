/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makui <makui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:44:11 by makui             #+#    #+#             */
/*   Updated: 2026/06/09 10:55:16 by makui            ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	double	player_x;
	double	player_y;
}	t_game;

int	close_game(t_game *game);
int	handle_keypress(int keycode, void *param);

#endif
