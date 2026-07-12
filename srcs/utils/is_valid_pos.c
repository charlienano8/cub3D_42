/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:38:48 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 11:39:58 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_pos(t_game *game, char **map_cpy, int player_x, int player_y)
{
	if (player_x < 0
		|| player_y < 0
		|| player_y >= game->line_map_nb
		|| player_x >= game->map_line_len[player_y])
		return (-1);
	if (map_cpy[player_y][player_x] == ' ')
		return (-1);
	if (map_cpy[player_y][player_x] != '1'
		&& map_cpy[player_y][player_x] != 'V')
		return (1);
	return (0);
}
