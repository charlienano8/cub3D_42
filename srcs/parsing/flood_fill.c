/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:06:18 by aborda            #+#    #+#             */
/*   Updated: 2026/07/05 15:57:32 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_pos(t_game *game, char **map_cpy, int player_x,
		int player_y)
{
	if (player_x < 0
		|| player_y < 0
		|| player_y >= game->line_map_nb
		|| player_x >= (int)ft_strlen(map_cpy[player_y]))
		return (-1);
	if (map_cpy[player_y][player_x] == ' ')
		return (-1);
	if (map_cpy[player_y][player_x] != '1'
		&& map_cpy[player_y][player_x] != 'V')
		return (1);
	return (0);
}

int	flood_fill(t_game *game, char **map_cpy, int player_x, int player_y)
{
	if (is_valid_pos(game, map_cpy, player_x, player_y) == -1)
		return (1);
	if (is_valid_pos(game, map_cpy, player_x, player_y) == 1)
	{
		map_cpy[player_y][player_x] = 'V';
		if (flood_fill(game, map_cpy, player_x + 1, player_y))
			return (1);
		if (flood_fill(game, map_cpy, player_x - 1, player_y))
			return (1);
		if (flood_fill(game, map_cpy, player_x, player_y + 1))
			return (1);
		if (flood_fill(game, map_cpy, player_x, player_y - 1))
			return (1);
	}
	return (0);
}
