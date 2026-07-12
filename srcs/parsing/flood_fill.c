/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:06:18 by aborda            #+#    #+#             */
/*   Updated: 2026/07/12 11:41:13 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
